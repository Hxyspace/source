#include<stdio.h>

typedef struct            //����
{
	int from,to,weight;   //�ߵ�ʼ�㡢�յ㡢Ȩ
} Eage;

typedef struct           //ͼ
{
	int numVertex;       //����ĸ���
	int numEdge;         //�ߵ�����
	int *Mark;           //����ķ��ʱ��
	int *Indegree;       //���ͼ�ж�������
	
} Graph;

void graph_traverse(Graph *G)
{
	int i;
	for(i = 0;i<G->)
}

int main()
{
	Graph G;
	
	return 0;
}