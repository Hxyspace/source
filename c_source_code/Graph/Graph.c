#include<stdio.h>

typedef struct            //边类
{
	int from,to,weight;   //边的始点、终点、权
} Eage;

typedef struct           //图
{
	int numVertex;       //顶点的个数
	int numEdge;         //边的条数
	int *Mark;           //顶点的访问标记
	int *Indegree;       //存放图中顶点的入度
	
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