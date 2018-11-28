/* 图的基本操作*/
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
#define ElemType char
#define MAXQISZE 50
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2

typedef enum { DG, DN, UDG, UDN } GraphKind;          //图类型：有向图、有向网、无向图、无向网
typedef struct ArcCell{
	int adj;                //顶点关系类型 对于无权图 用0或1表示
	//char *info;           //弧相关信息的指针
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
	char vers[MAX_VERTEX_NUM];     //用一个字符数组存储顶点向量
	AdjMatrix arcs;                //邻接矩阵
	int vexnum, arcnum;            //图的当前顶点数和弧数
	GraphKing king;                //图的种类标志
	int in[MAX_VERTEX_NUM];         //存放所有节点的入度
}MGraph;

typedef int SElemType;

typedef struct sqStack
{
	SElemType *base;                     //基地址
	SElemType *top;                      //栈顶指针
	int stacksize;                       //当前已经分配的存储空间
}sqStack;


int InitStack1(SqStack1 *S);
int StackEmpty1(SqStack1 *S);
int Push(SqStack1 *S, SElemType e);
int Pop(SqStack1 *S, SElemType *e);

//图G中顶点v的第一个邻接点，不存在时返回 -1
int FirstAdjVex(MGraph *G, int v)
{
	int i;
	for (i = 0; i < G->vexnum; i++)
	{
		if (G->arcs[v][i].adj)
		{
			return i;
		}
	}
	return -1;
}

//图G中顶点v在w之后的下一个邻接点，不存在时返回 -1
int NextAdjVex(MGraph G, int v, int w)
{
	int i;
	for(int = w+1; i<G.vexnum; i++)
	{
		if(G.arcs[v][i].adj)
		{
			return i;
		}
	}
	return -1;
}

//深度优先遍历图
_Bool visited[MAX_VERTEX_NUM];
void DFS(MGraph G, int v)
{
	int j;
	visited[v] = true;
	printf("%c",G.vers[v]);
	for(j = 1;j <= G.vexnum; j++)
	{
		if(visited[j] == 0 && G.arcs[v][j].adj ==1)
		{
			DFS(G,j);
		}
	}
}

//广度优先遍历
int BFSTraverse(MGraph G,int s)
{
	int Q[MAX_VERTEX_NUM];    //定义队列，用于保存当前节点的邻接顶点
	int front = 0 ,rear = 0;
	int i,j;
	//清空访问标志
	for(i=0;i < MAX_VERTEX_NUM; i++)
		visited[i] = false;
	printf("%c", G.vers[s]);
	visited[s] = 1;
	Q[rear++] = s;
	while (front < rear)         //遍历队列
	{
		i = Q[front++];
		for(j = 1; j <= G.vexnum; j++)
		{
			if(visited[j] == false && G.arcs[i][j].adj == 1)
			{
				printf("%c",G.vers[j]);
				visited[j] = true;
				Q[rear++] = j;
			}
		}
	}
	return  0;
}

int LocateVex(MGraph *G, char v)
{
	int i;
	for(i = 0; i<G->vexnum; i++)
	{
		if (v == G->vers[i])
		{
			return i;
		}
	}
	return -1;
}

int CreateDG(MGraph *G)       //创建有向图
{
	int i,j,k;
	char v1,v2;
	printf("请输入顶点数：");
	scanf("%d",&G->vexnum);
	printf("\n请输入弧数：");
	scanf("%d",&G->arcnum);
	printf("请输入%d个顶点：（每个顶点之间用空格隔开）",G->vexnum);
	while(getchar() != '\n');
	for(i = 0;i < G->vexnum;i++)
	{
		scanf("%c",&G->vers[i]);
		getchar();
	}
	for(i = 0;i < G->vexnum;i++)    //打印输出各个顶点
	{
		printf("%c",G->verx[i]);
	}
	putchar('\n');
	for(i = 0; i < G->vexnum;i++)
	{
		for(j = 0;j<G->vexnum;j++)
		{
			G->arcs[i][j].adj = INFINITY;
		}
	}
	for(i = 0;i < G->arcnum;i++)     //入度初始化
	{
		G->in[i] = 0;
	}
	for(k = 0;k < G->arcnum; k++)
	{
		printf("\nplease input <v1 v2>:");
		fflush(stdin);
		scanf("%c %c",&v1,&v2);      // v1 v2之间用空格隔开
		fflush(stdin);      //清除缓冲区
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		G->arcs[i][j].adj = 1;
		G->in[j]++;
	}
	return 1;
}

int CreateDN(MGraph *G)         //创建有向网
{
	int i,j,k,w;
	char v1,v2;
	printf("请输入顶点数：");
	scanf("%d",&G->vexnum);
	printf("\n请输入弧的数目：");
	scanf("%d",&G->arcnum);
	printf("请输入%d个顶点：（每个顶点之间用空格隔开）"，G->vexnum);
	while(getchar()!= '\n');     //清除缓冲区
	for(i = 0;i<G->vexnum;i++)
	{
		scanf("%c",&G->vers[i]);
		getchar();                  //清除空格
	}
	//打印输出各个顶点
	for(i = 0;i < G->vexnum; i++)
	{
		printf("%c",G->vers[i]);
	}
	putchar('\n');
	//初始化邻接矩阵
	for(i = 0;i < G->vexnum;i++)
	{
		for(j = 0;j < G->vexnum;j++)
		{
			G->arcs[i][j].adj = INFINITY;
		}
	}
	for(k = 0;k < G->arcnum;k++)
	{
		printf("\n please input <v1 v2 w>: ");
		fflush(stdin);       //清除缓冲区
		scanf("%c %c %d",&v1,&v2,&w);
		fflush(stdin);
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		G->arcs[i][j].adj = w;
	}
	return 1;
}

//创建无向图
int CreateUDG(MGraph *G)
{
	int i,j,k;
	char v1,v2;
	printf("请输入顶点数：");
	scanf("%d",&G->vexnum);
	printf("\n请输入边数：");
	scanf("%d",&G->arcnum);
	printf("请输入%d个顶点：（每个顶点之间用空格隔开）"，G->vexnum);
	fflush(stdin);
	for(i = 0;i<G->vexnum;i++)
	{
		scanf("%c",&G->vers[i]);
		getchar();                //吃掉空格  注意数组vers[i]的初始大小为20
	}
	//打印输出各个顶点
	for (i = 0;i<G->vexnum;i++)
		printf("%c",G->vers[i]);
	putchar('\n');
	for(i = 0;i<G->vexnum;i++)
	{
		for(j = 0;j<G->vexnum;j++)
		{
			G->arcs[i][j].adj = INFINITY;
		}
	}
	for(k = 0;k<G->grcnum;k++)
	{
		printf("\nplease input <v1 v2>:");
		fflush(stdin);
		scanf("%c %c",&v1,V2);
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		G->arcs[i][j].adj = 1;
		G->arcs[j][i].adj = 1;
		getchar();
	}
	return 1;
}

//创建无向网
int CreateUDN(MGraph *G)
{
	int i,j,k,w;
	char v1,v2;
	printf("请输入顶点数：");
	scanf("%d",&G->vexnum);
	printf("\n请输入边的数目：");
	scanf("%d",&G->arcnum);
	printf("请输入%d个顶点：（每个顶点之间用空格隔开）",G->vexnum);
	fflush(stdin);
	for(i = 0;i<G->vexnum;i++)
	{
		scanf("%c",&G->vers[i]);
		getchar();
	}
	//打印输出各个顶点
	for(i = 0;i<G->vexnum;i++)
	{
		printf("%c ",G->vers[i]);
	}
	putchar('\n');
	//初始化邻接矩阵
	for(i = 0;i<G->vexnum;i++)
	{
		for(j = 0;j<G->vexnum;j++)
		{
			G->arcs[i][j].adj = INFINITY;
		}
	}
	for(k = 0;k<G->arcnum;k++)
	{
		printf("\n please input <v1 v2 w>:");
		fflush(stdin);
		scanf("%c %c %d",&v1,&v2,&w);
		fflush(stdin);
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		G->arcs[i][j].adj = w;
		G->arcs[j][i].adj = w;
	}
	return 1;
}

int main()
{
	return 0;
}