#include "queue.h"
#include "huffman.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void traverseTree(htNode *treeNode, hlTable **table, int k, char code[256])
{
    if(treeNode->left == NULL && treeNode->right == NULL)
    {
        code[k] = '\0';
        hlNode *aux = (hlNode *)malloc(sizeof(hlNode));
        aux->code = (char *)malloc(sizeof(char) * (strlen(code)+1));
        strcpy(aux->code, code);
        aux->symbol = treeNode->symbol;
        aux->next = NULL;

        if((*table)->first == NULL)
        {
            (*table)->first = aux;
            (*table)->last = aux;
        }
        else
        {
            (*table)->last->next = aux;
            (*table)->last = aux;
        }

        if(treeNode->left != NULL)
        {
            code[k] = '0';
            traverseTree(treeNode->left, table, k+1, code);
        }

        if(treeNode->right != NULL)
        {
            code[k] = '1';
            traverseTree(treeNode->right, table, k+1, code);
        }
        
    }
}

hlTable * buildTable(htTree * huffmanTree)
{
    hlTable *table = (hlTable *)malloc(sizeof(hlTable));
    table->first = NULL;
    table->last = NULL;

    char code[256];
    int k = 0;

    traverseTree(huffmanTree->root, &table, k, code);
    return table;
}

htTree * buildTree(char *inputString)
{
    int * probability = (int *)malloc(sizeof(int)*256);     /* 存放每个字符的个数 */

    for(int i=0; i < 256; i++)  /* 初始化数组 */
    {
        probability[i] = 0;
    }

    //统计待编码的字符串各个字符出现的次数
    for(int j=0; inputString[j] != '\0'; j++)
    {
        probability[(unsigned char) inputString[j]]++;      
    }

    //队列头指针
    pQueue * huffmanQueue;
    initPQueue(&huffmanQueue);

    //填充队列
    for (int k = 0; k < 256; k++)
    {
        if(probability[k] != 0)
        {
            htNode *aux = (htNode *)malloc(sizeof(htNode));
            aux->left = NULL;
            aux->right = NULL;
            aux->symbol = (char) k;

            addpQueue(&huffmanQueue, aux, probability[k]);
        }
    }

    free(probability);

    //生成huffman树
    while(huffmanQueue->size != 1)      //循环直到队列中只剩树的根节点
    {
        int priority = huffmanQueue->first->priority;
        priority += huffmanQueue->first->next->priority;        /* 新生成树节点的权值等于两个最小树节点权值之和 */

        htNode *left = getPQueue(&huffmanQueue);
        htNode *right = getPQueue(&huffmanQueue);

        htNode *newNode = (htNode *)malloc(sizeof(htNode));
        newNode->left = left;       /* 左孩子为权值最小的树节点 */
        newNode->right = right;

        addpQueue(&huffmanQueue, newNode, priority);        /* 将新生成的树节点放回队列中 */
    }

    htTree *tree = (htTree *)malloc(sizeof(htTree));

    tree->root = getPQueue(&huffmanQueue);

    return tree;

}

