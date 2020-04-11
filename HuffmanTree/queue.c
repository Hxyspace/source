#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void initPQueue(pQueue **queue)
{
    (*queue) = (pQueue *)malloc(sizeof(pQueue));
    (*queue)->first = NULL;
    (*queue)->size = 0;
    return;
}

void addPQueue(pQueue **queue, TYPE val, unsigned int priority)
{
    if((*queue)->size == MAX_SZ)
    {
        printf("\nQueue if full.\n");
        return;
    }

    pQueueNode *aux = (pQueueNode *)malloc(sizeof(pQueueNode));
    aux->priority = priority;
    aux->val = val;

    if((*queue)->size == 0 || (*queue)->first == NULL)      /* 如果队列为空，直接插入第一个 */
    {
        aux->next = NULL;
        (*queue)->first = aux;
        (*queue)->size = 1;
        return;
    }
    else
    {
        pQueueNode * iterator = (*queue)->first;
        while(iterator->next != NULL)
        {
            if(priority <= iterator->next->priority)
            {
                aux->next = iterator->next;
                iterator->next = aux;
                (*queue)->size++;
                return;
            }
        }

        if(iterator->next == NULL)
        {
            aux->next = NULL;
            iterator->next = aux;
            (*queue)->size++;
            return;
        }
    }
}

TYPE getPQueue(pQueue **queue)
{
    TYPE returnValue;

    if((*queue)->size > 0)
    {
        returnValue = (*queue)->first->val;
        (*queue)->first = (*queue)->first->next;
        (*queue)->size--;
    }
    else
    {
        printf("\nQueue is empty.\n");
    }
    return returnValue;
    
}