#pragma once
#ifndef _QUEUE_H
#define _QUEUE_H

#include "huffman.h"

#define TYPE htNode *

#define MAX_SZ 256

typedef struct _pQueueNode {    /* 队列节点 */
    TYPE val;                   /* 指向树节点的指针 */
    unsigned int priority;
    struct _pQueueNode *next;
}pQueueNode;

typedef struct _pQueue {    /* 队列 */
    unsigned int size;
    pQueueNode *first;
}pQueue;

void initPQueue(pQueue **queue);    /* 队列初始化 */
void addpQueue(pQueue **queue , TYPE val,unsigned int priority);    /* 根据priority排序插入队列 */
TYPE getPQueue(pQueue **queue);     /* 获取队列元素 */


#endif