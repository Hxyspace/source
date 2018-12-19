/* ͼ�Ļ�������*/
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

typedef enum { DG, DN, UDG, UDN } GraphKind;          //ͼ���ͣ�����ͼ��������������ͼ��������
typedef struct ArcCell{
	int adj;                //�����ϵ���� ������Ȩͼ ��0��1��ʾ
	//char *info;           //�������Ϣ��ָ��
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef struct{
	char vers[MAX_VERTEX_NUM];     //��һ���ַ�����洢��������
	AdjMatrix arcs;                //�ڽӾ���
	int vexnum, arcnum;            //ͼ�ĵ�ǰ�������ͻ���
	GraphKing king;                //ͼ�������־
	int in[MAX_VERTEX_NUM];         //������нڵ�����
}MGraph;

typedef int SElemType;

typedef struct sqStack
{
	SElemType *base;                     //����ַ
	SElemType *top;                      //ջ��ָ��
	int stacksize;                       //��ǰ�Ѿ�����Ĵ洢�ռ�
}sqStack;


int InitStack1(SqStack1 *S);
int StackEmpty1(SqStack1 *S);
int Push(SqStack1 *S, SElemType e);
int Pop(SqStack1 *S, SElemType *e);

//ͼG�ж���v�ĵ�һ���ڽӵ㣬������ʱ���� -1
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

//ͼG�ж���v��w֮�����һ���ڽӵ㣬������ʱ���� -1
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

//������ȱ���ͼ
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

//������ȱ���
int BFSTraverse(MGraph G,int s)
{
	int Q[MAX_VERTEX_NUM];    //������У����ڱ��浱ǰ�ڵ���ڽӶ���
	int front = 0 ,rear = 0;
	int i,j;
	//��շ��ʱ�־
	for(i=0;i < MAX_VERTEX_NUM; i++)
		visited[i] = false;
	printf("%c", G.vers[s]);
	visited[s] = 1;
	Q[rear++] = s;
	while (front < rear)         //��������
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

int CreateDG(MGraph *G)       //��������ͼ
{
	int i,j,k;
	char v1,v2;
	printf("�����붥������");
	scanf("%d",&G->vexnum);
	printf("\n�����뻡����");
	scanf("%d",&G->arcnum);
	printf("������%d�����㣺��ÿ������֮���ÿո������",G->vexnum);
	while(getchar() != '\n');
	for(i = 0;i < G->vexnum;i++)
	{
		scanf("%c",&G->vers[i]);
		getchar();
	}
	for(i = 0;i < G->vexnum;i++)    //��ӡ�����������
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
	for(i = 0;i < G->arcnum;i++)     //��ȳ�ʼ��
	{
		G->in[i] = 0;
	}
	for(k = 0;k < G->arcnum; k++)
	{
		printf("\nplease input <v1 v2>:");
		fflush(stdin);
		scanf("%c %c",&v1,&v2);      // v1 v2֮���ÿո����
		fflush(stdin);      //���������
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		G->arcs[i][j].adj = 1;
		G->in[j]++;
	}
	return 1;
}

int CreateDN(MGraph *G)         //����������
{
	int i,j,k,w;
	char v1,v2;
	printf("�����붥������");
	scanf("%d",&G->vexnum);
	printf("\n�����뻡����Ŀ��");
	scanf("%d",&G->arcnum);
	printf("������%d�����㣺��ÿ������֮���ÿո������"��G->vexnum);
	while(getchar()!= '\n');     //���������
	for(i = 0;i<G->vexnum;i++)
	{
		scanf("%c",&G->vers[i]);
		getchar();                  //����ո�
	}
	//��ӡ�����������
	for(i = 0;i < G->vexnum; i++)
	{
		printf("%c",G->vers[i]);
	}
	putchar('\n');
	//��ʼ���ڽӾ���
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
		fflush(stdin);       //���������
		scanf("%c %c %d",&v1,&v2,&w);
		fflush(stdin);
		i = LocateVex(G,v1);
		j = LocateVex(G,v2);
		G->arcs[i][j].adj = w;
	}
	return 1;
}

//��������ͼ
int CreateUDG(MGraph *G)
{
	int i,j,k;
	char v1,v2;
	printf("�����붥������");
	scanf("%d",&G->vexnum);
	printf("\n�����������");
	scanf("%d",&G->arcnum);
	printf("������%d�����㣺��ÿ������֮���ÿո������"��G->vexnum);
	fflush(stdin);
	for(i = 0;i<G->vexnum;i++)
	{
		scanf("%c",&G->vers[i]);
		getchar();                //�Ե��ո�  ע������vers[i]�ĳ�ʼ��СΪ20
	}
	//��ӡ�����������
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

//����������
int CreateUDN(MGraph *G)
{
	int i,j,k,w;
	char v1,v2;
	printf("�����붥������");
	scanf("%d",&G->vexnum);
	printf("\n������ߵ���Ŀ��");
	scanf("%d",&G->arcnum);
	printf("������%d�����㣺��ÿ������֮���ÿո������",G->vexnum);
	fflush(stdin);
	for(i = 0;i<G->vexnum;i++)
	{
		scanf("%c",&G->vers[i]);
		getchar();
	}
	//��ӡ�����������
	for(i = 0;i<G->vexnum;i++)
	{
		printf("%c ",G->vers[i]);
	}
	putchar('\n');
	//��ʼ���ڽӾ���
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