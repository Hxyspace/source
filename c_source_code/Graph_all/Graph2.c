#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0

#define MAX_VERTEX_NUM 100
typedef char VertexType;
typedef int EdgeType;

typedef struct           //邻接矩阵无向图
{
	VertexType vers[MAX_VERTEX_NUM];                    //顶点
	EdgeType edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];     //边
	int n,e;         //顶点个数、边数
}MGraph;

typedef struct node       //边节点
{
	int adjvex;         //邻接点
	struct node *next;  //指向下一个邻接点
}EdgeNode;

typedef struct            //头结点
{
	VertexType vertex;    //顶点
	EdgeNode *edgefirst;   //指向第一条边
}VertexNode,AdjList[MAX_VERTEX_NUM];

typedef struct            //邻接表无向图
{
	int n,e;          //顶点个数、边数
	AdjList adjList;
}Graph;

void CreateUDG(MGraph *G)                 //创建无向图 邻接矩阵
{
	int i,j,k;
	printf("输入顶点数和边数：\n");
	scanf("%d%d",&(G->n),&(G->e));
	printf("\n输入%d个顶点（每个顶点用一个空格隔开）: \n",G->n);
	getchar();               //清除回车
	for(i = 0;i<G->n;i++)
	{
		scanf("%c",&(G->vers[i]));
		getchar();                     //清除空格
	}
	for(i = 0;i<G->n;i++)
	{
		for(j = 0;j<G->n;j++)
			G->edges[i][j] = 0;        //初始化邻接矩阵
	}
	printf("\n输入每条边的两个顶点所在的位置：\n");
	for(k = 0;k<G->e;k++)
	{
		scanf("%d%d",&i,&j);
		G->edges[i][j] = G->edges[j][i] = 1;
	}
	printf("\n打印邻接矩阵：\n");
	for(i = 0;i<G->n;i++)
	{
		for(j = 0;j<G->n;j++)
			printf("%2d",G->edges[i][j]);
		putchar('\n');
	}
}

int visited[MAX_VERTEX_NUM] = {0};      //用于标记顶点是否已被遍历
void DFS(MGraph G,int i)                //深度优先遍历     i表示顶点所在的位置
{
	int j;
	visited[i] = 1;                     //标记已读
	printf("%c ",G.vers[i]);            //输出
	for(j = 0;j<G.n;j++)
		if(visited[j] == 0 && G.edges[i][j] == 1)     //未被遍历过，且i 与 j之间有边   则访问
			DFS(G,j);                                 //每次循环i都变化，把这次的j赋值给下一次的i
}

void CreateALGraph(Graph *G)           //邻接表创建无向图
{
	int i,j,k;
	EdgeNode *s;
	printf("输入结点数和边数：\n");
	scanf("%d%d",&(G->n),&(G->e));
	fflush(stdin);          //清除缓冲区
	printf("\n输入各顶点的数据(两个顶点之间用空格隔开)：\n");
	for(i = 0;i<G->n;i++)
	{
		scanf("%c",&(G->adjList[i].vertex));
		G->adjList[i].edgefirst = NULL;
		getchar();
	}
	printf("\n输入每条边的两个顶点所在的位置：\n");
	for(k = 0;k<G->e;k++)
	{
		
		s = (EdgeNode *)malloc(sizeof(EdgeNode));
		scanf("%d%d",&i,&j);
		s->adjvex = j;
		s->next = G->adjList[i].edgefirst;
		G->adjList[i].edgefirst = s;
		//无向图  所以需要对另外一点作相同的操作
		s = (EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex = i;
		s->next = G->adjList[j].edgefirst;
		G->adjList[j].edgefirst = s;
	}
}

void BFS(Graph G)
{
	int i,k;
	int Q[MAX_VERTEX_NUM];            //定义数组作为队列
	int front = 0,rear = 0;
	EdgeNode *p;
	for(i = 0;i<G.n;i++)
	{
		visited[i] = 0;        //访问标志初始化
	}
	for(i = 0;i<G.n;i++)
	{
		if(!visited[i])
		{
			visited[i] = 1;
			printf("%c ",G.adjList[i].vertex);
			Q[rear++] = i;                             //将访问过的结点所在位置放入队列
			while(front<rear)
			{
				k = Q[front++];                        //出队
				p = G.adjList[k].edgefirst;           //p指向该结点的下一个结点
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex] = 1;
						printf("%c ",G.adjList[p->adjvex].vertex);
						Q[rear++] = p->adjvex;                      //将访问过的结点所在位置放入队列
					}
					p = p->next;            //指向下一个结点
				}
			}
		}
	}
}
int main()
{
	MGraph G1;          //邻接矩阵无向图
	Graph G2;           //邻接表无向图
	int ch,i;
	printf("\t\t\t主函数测试\n\n");
	printf("\n1.邻接矩阵创建无向图\n2.邻接表创建无向图\n3.深度遍历\n4.广度遍历\n0.退出\n");
	scanf("%d",&ch);
	while(ch)
	{
	switch (ch)
	{
		case 1:
			CreateUDG(&G1);
			printf("\n创建成功\n");break;
		case 2:
			CreateALGraph(&G2);
			printf("\n创建成功\n");break;
		case 3:
			for(i = 0;i<G1.n;i++)
				{
					visited[i] = 0;        //访问标志初始化
				}
			DFS(G1,0);break;
		case 4:
			BFS(G2);break;
		default:
			printf("\n\t非法输入，请重新输入：\n");
	}
	printf("\n\n\t\t\t主函数测试\n\n");
	printf("\n1.邻接矩阵创建无向图\n2.邻接表创建无向图\n3.深度遍历\n4.广度遍历\n0.退出\n");
	scanf("%d",&ch);
	}

	return 0;
}