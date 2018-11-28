#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0

#define MAX_VERTEX_NUM 100
typedef char VertexType;
typedef int EdgeType;

typedef struct           //�ڽӾ�������ͼ
{
	VertexType vers[MAX_VERTEX_NUM];                    //����
	EdgeType edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];     //��
	int n,e;         //�������������
}MGraph;

typedef struct node       //�߽ڵ�
{
	int adjvex;         //�ڽӵ�
	struct node *next;  //ָ����һ���ڽӵ�
}EdgeNode;

typedef struct            //ͷ���
{
	VertexType vertex;    //����
	EdgeNode *edgefirst;   //ָ���һ����
}VertexNode,AdjList[MAX_VERTEX_NUM];

typedef struct            //�ڽӱ�����ͼ
{
	int n,e;          //�������������
	AdjList adjList;
}Graph;

void CreateUDG(MGraph *G)                 //��������ͼ �ڽӾ���
{
	int i,j,k;
	printf("���붥�����ͱ�����\n");
	scanf("%d%d",&(G->n),&(G->e));
	printf("\n����%d�����㣨ÿ��������һ���ո������: \n",G->n);
	getchar();               //����س�
	for(i = 0;i<G->n;i++)
	{
		scanf("%c",&(G->vers[i]));
		getchar();                     //����ո�
	}
	for(i = 0;i<G->n;i++)
	{
		for(j = 0;j<G->n;j++)
			G->edges[i][j] = 0;        //��ʼ���ڽӾ���
	}
	printf("\n����ÿ���ߵ������������ڵ�λ�ã�\n");
	for(k = 0;k<G->e;k++)
	{
		scanf("%d%d",&i,&j);
		G->edges[i][j] = G->edges[j][i] = 1;
	}
	printf("\n��ӡ�ڽӾ���\n");
	for(i = 0;i<G->n;i++)
	{
		for(j = 0;j<G->n;j++)
			printf("%2d",G->edges[i][j]);
		putchar('\n');
	}
}

int visited[MAX_VERTEX_NUM] = {0};      //���ڱ�Ƕ����Ƿ��ѱ�����
void DFS(MGraph G,int i)                //������ȱ���     i��ʾ�������ڵ�λ��
{
	int j;
	visited[i] = 1;                     //����Ѷ�
	printf("%c ",G.vers[i]);            //���
	for(j = 0;j<G.n;j++)
		if(visited[j] == 0 && G.edges[i][j] == 1)     //δ������������i �� j֮���б�   �����
			DFS(G,j);                                 //ÿ��ѭ��i���仯������ε�j��ֵ����һ�ε�i
}

void CreateALGraph(Graph *G)           //�ڽӱ�������ͼ
{
	int i,j,k;
	EdgeNode *s;
	printf("���������ͱ�����\n");
	scanf("%d%d",&(G->n),&(G->e));
	fflush(stdin);          //���������
	printf("\n��������������(��������֮���ÿո����)��\n");
	for(i = 0;i<G->n;i++)
	{
		scanf("%c",&(G->adjList[i].vertex));
		G->adjList[i].edgefirst = NULL;
		getchar();
	}
	printf("\n����ÿ���ߵ������������ڵ�λ�ã�\n");
	for(k = 0;k<G->e;k++)
	{
		
		s = (EdgeNode *)malloc(sizeof(EdgeNode));
		scanf("%d%d",&i,&j);
		s->adjvex = j;
		s->next = G->adjList[i].edgefirst;
		G->adjList[i].edgefirst = s;
		//����ͼ  ������Ҫ������һ������ͬ�Ĳ���
		s = (EdgeNode *)malloc(sizeof(EdgeNode));
		s->adjvex = i;
		s->next = G->adjList[j].edgefirst;
		G->adjList[j].edgefirst = s;
	}
}

void BFS(Graph G)
{
	int i,k;
	int Q[MAX_VERTEX_NUM];            //����������Ϊ����
	int front = 0,rear = 0;
	EdgeNode *p;
	for(i = 0;i<G.n;i++)
	{
		visited[i] = 0;        //���ʱ�־��ʼ��
	}
	for(i = 0;i<G.n;i++)
	{
		if(!visited[i])
		{
			visited[i] = 1;
			printf("%c ",G.adjList[i].vertex);
			Q[rear++] = i;                             //�����ʹ��Ľ������λ�÷������
			while(front<rear)
			{
				k = Q[front++];                        //����
				p = G.adjList[k].edgefirst;           //pָ��ý�����һ�����
				while(p)
				{
					if(!visited[p->adjvex])
					{
						visited[p->adjvex] = 1;
						printf("%c ",G.adjList[p->adjvex].vertex);
						Q[rear++] = p->adjvex;                      //�����ʹ��Ľ������λ�÷������
					}
					p = p->next;            //ָ����һ�����
				}
			}
		}
	}
}
int main()
{
	MGraph G1;          //�ڽӾ�������ͼ
	Graph G2;           //�ڽӱ�����ͼ
	int ch,i;
	printf("\t\t\t����������\n\n");
	printf("\n1.�ڽӾ��󴴽�����ͼ\n2.�ڽӱ�������ͼ\n3.��ȱ���\n4.��ȱ���\n0.�˳�\n");
	scanf("%d",&ch);
	while(ch)
	{
	switch (ch)
	{
		case 1:
			CreateUDG(&G1);
			printf("\n�����ɹ�\n");break;
		case 2:
			CreateALGraph(&G2);
			printf("\n�����ɹ�\n");break;
		case 3:
			for(i = 0;i<G1.n;i++)
				{
					visited[i] = 0;        //���ʱ�־��ʼ��
				}
			DFS(G1,0);break;
		case 4:
			BFS(G2);break;
		default:
			printf("\n\t�Ƿ����룬���������룺\n");
	}
	printf("\n\n\t\t\t����������\n\n");
	printf("\n1.�ڽӾ��󴴽�����ͼ\n2.�ڽӱ�������ͼ\n3.��ȱ���\n4.��ȱ���\n0.�˳�\n");
	scanf("%d",&ch);
	}

	return 0;
}