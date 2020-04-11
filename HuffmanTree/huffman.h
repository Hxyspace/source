#pragma once
#ifndef _HUFFMAN_H
#define _HUFFMAN_H

typedef struct _htNode { /* 树节点 */
    char symbol;
    struct _htNode *left, *right;
    
}htNode;

typedef struct _hlTree { /* 根节点 */
    htNode *root;
}htTree;

typedef struct _hlNode {
    char symbol;
    char *code;
    struct _hlNode *next;
}hlNode;

typedef struct _hlTable {   /* Huffman表 */
    hlNode *first;
    hlNode *last;
}hlTable;

hlTable * buildTable(htTree * huffmanTree);
htTree * buildTree(char *inputString);

#endif