/* ͼ�Ļ������� */
#include<stdio.h>
#include"stdlib.h"
#define true 1
#define false 0
#define ElemType char
#define MAXQSIZE 50
#define INFINITY INT_MAX
#define MAX_VERTEX_NUM 20
typedef enum { DG, DN, UDG, UDN } GraphKind;               //ͼ���ͣ�����ͼ��������������ͼ��������
typedef struct ArcCell {
    int adj;         //�����ϵ���� ������Ȩͼ ��0��1��ʾ
                     //char *info;     //�������Ϣ��ָ��
}ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
    char vers[MAX_VERTEX_NUM];  //��һ���ַ�����洢��������
    AdjMatrix arcs;            //�ڽӾ���
    int vexnum, arcnum;         //ͼ�ĵ�ǰ�������ͻ��� 
    GraphKind kind;               //ͼ�������־
    int in[MAX_VERTEX_NUM];  //������нڵ�����
}MGraph;
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
    for (i = w + 1; i < G.vexnum; i++)
    {
        if (G.arcs[v][i].adj)
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
    visited[v] = true;
    printf("%c", G.vers[v]);
    int j;
    for (j = 1; j <= G.vexnum; j++) {
        if (visited[j] == 0 && G.arcs[v][j].adj == 1)
        {
            DFS(G, j);//vÿѭ��һ��ֵ����� ��һ�ֵ�jֵ������v
        }
    }
}

//������ȱ���
int BFSTraverse(MGraph G, int s)
{
    //��շ��ʱ�־  
    for (int i = 0; i <MAX_VERTEX_NUM; i++)
        visited[i] = false;
    //������У����ڱ��浱ǰ�ڵ���ڽӶ���  
    int Q[MAX_VERTEX_NUM];
    int front = 0;
    int rear = 0;
    int i, j;
    printf("%c", G.vers[s]);
    visited[s] = 1;
    Q[rear++] = s;
    //��������   
    while (front < rear)
    {
        i = Q[front++];
        for (j = 1; j <= G.vexnum; j++)
        {
            if (visited[j] == false && G.arcs[i][j].adj == 1)
            {
                printf("%c", G.vers[j]);
                visited[j] = true;
                Q[rear++] = j;
            }

        }
    }
    return 0;
}

//��λ����
int LocateVex(MGraph *G, char v)
{
    int i;
    for (i = 0; i<G->vexnum; i++)
    {
        if (v == G->vers[i])
        {
            return i;
        }
    }
    return -1;

}

//��������ͼ
int CreateDG(MGraph *G) {
    int i, j, k;
    char v1, v2;
    printf("�����붥����:");
    scanf("%d", &G->vexnum);
    printf("\n�����뻡��:");
    scanf("%d", &G->arcnum);
    printf("������%d�����㣺(ÿ������֮���ÿո����)", G->vexnum);
    fflush(stdin);
    getchar(); //�Ե��ո�
    for (i = 0; i < G->vexnum; i++)
    {
        scanf("%c", &G->vers[i]);
        getchar();  //�Ե��ո� ע������vers[i]�ĳ�ʼ��СΪ20
    }
    //��ӡ�����������
    for (i = 0; i < G->vexnum; i++)
    {
        printf("%c", G->vers[i]);

    }
    printf("\n");
    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;

        }
    }
    //��ȳ�ʼ��
    for (int i = 0; i < G->vexnum; i++)
    {
        G->in[i] = 0;
    }
    for (k = 0; k < G->arcnum; k++)
    {
        printf("\nplease input <v1 v2>:");
        fflush(stdin);
        scanf("%c %c", &v1, &v2);  //v1 v2 ֮���ÿո����
        fflush(stdin);//�������󣬺����ٶ���ʱ�������
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G->arcs[i][j].adj = 1;
        G->in[j]++;
        getchar();
    }
    return 1;
}

//����������
int CreateDN(MGraph *G) {
    int i, j, k, w;
    char v1, v2;
    printf("�����붥������");
    scanf("%d", &G->vexnum);
    printf("\n�����뻡����Ŀ:");
    scanf("%d", &G->arcnum);
    printf("������%d�����㣺(ÿ������֮���ÿո����)", G->vexnum);
    fflush(stdin);
    getchar(); //�Ե��ո�
    for (i = 0; i < G->vexnum; i++)
    {
        scanf("%c", &G->vers[i]);
        getchar();  //�Ե��ո� ע������vers[i]�ĳ�ʼ��СΪ20
    }
    //��ӡ�����������
    for (i = 0; i < G->vexnum; i++)
    {
        printf("%c", G->vers[i]);

    }
    printf("\n");
    //��ʼ���ڽӾ���
    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;

        }
    }
    for (k = 0; k < G->arcnum; k++)
    {
        printf("\n please input <v1 v2 w>:");
        fflush(stdin);
        scanf("%c %c %d", &v1, &v2, &w);  //v1 v2 w֮���ÿո����
        fflush(stdin);//�������󣬺����ٶ���ʱ�������
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G->arcs[i][j].adj = w;

        getchar();  //�Ե��ո�
    }
    return 1;
}

//��������ͼ
int CreateUDG(MGraph *G)
{
    int i, j, k;
    char v1, v2;
    printf("�����붥����:");
    scanf("%d", &G->vexnum);
    printf("\n���������:");
    scanf("%d", &G->arcnum);
    printf("������%d�����㣺(ÿ������֮���ÿո����)", G->vexnum);
    fflush(stdin);
    for (i = 0; i < G->vexnum; i++)
    {
        scanf("%c", &G->vers[i]);
        getchar();  //�Ե��ո� ע������vers[i]�ĳ�ʼ��СΪ20
    }
    //��ӡ�����������
    for (i = 0; i < G->vexnum; i++)
    {
        printf("%c", G->vers[i]);

    }
    printf("\n");
    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;
        }
    }
    for (k = 0; k < G->arcnum; k++)
    {
        printf("\nplease input <v1 v2>:");
        fflush(stdin);
        scanf("%c %c", &v1, &v2);  //v1 v2 ֮���ÿո����
        fflush(stdin);//�������󣬺����ٶ���ʱ�������
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G->arcs[i][j].adj = 1;
        G->arcs[j][i].adj = 1;
        getchar();
    }
    return 1;
}

//����������
int CreateUDN(MGraph *G)
{
    int i, j, k, w;
    char v1, v2;
    printf("�����붥������");
    scanf("%d", &G->vexnum);
    printf("\n������ߵ���Ŀ:");
    scanf("%d", &G->arcnum);
    printf("������%d�����㣺(ÿ������֮���ÿո����)", G->vexnum);
    fflush(stdin);
    getchar(); //�Ե��ո�
    for (i = 0; i < G->vexnum; i++)
    {
        scanf("%c", &G->vers[i]);
        getchar();  //�Ե��ո� ע������vers[i]�ĳ�ʼ��СΪ20
    }
    //��ӡ�����������
    for (i = 0; i < G->vexnum; i++)
    {
        printf("%c", G->vers[i]);

    }
    printf("\n");
    //��ʼ���ڽӾ���
    for (i = 0; i < G->vexnum; i++)
    {
        for (j = 0; j < G->vexnum; j++)
        {
            G->arcs[i][j].adj = INFINITY;
        }
    }
    for (k = 0; k < G->arcnum; k++)
    {
        printf("\n please input <v1 v2 w>:");
        fflush(stdin);
        scanf("%c %c %d", &v1, &v2, &w);  //v1 v2 w֮���ÿո����
        fflush(stdin);//�������󣬺����ٶ���ʱ�������
        i = LocateVex(G, v1);
        j = LocateVex(G, v2);
        G->arcs[i][j].adj = w;
        G->arcs[j][i].adj = w;
        getchar();  //�Ե��ո�
    }
    return 1;
}
//ջ����
typedef int SElemType;
#define STACK_INIT_SIZE1 10                                      //�洢�ռ��ʼ������
#define STACKINCREMENT1 2                                        //�洢�ռ��������

//ջ��˳��洢�ṹ��ʾ
typedef struct SqStack1
{
    SElemType *base;                        //����ַ
    SElemType *top;                         //ջ��ָ��
    int stacksize1;                          //��ǰ�Ѿ�����Ĵ洢�ռ�
}SqStack1;

//����һ����ջ
int InitStack1(SqStack1 *S)
{
    //Ϊջ�׷ַ���һ��ָ����С�Ĵ洢�ռ�
    S->base = (SElemType *)malloc(STACK_INIT_SIZE1 * sizeof(SElemType));
    if (!S->base)
        exit(0);
    S->top = S->base;                   //ջ����ջ��ָ����ͬ
    S->stacksize1 = STACK_INIT_SIZE1;
    return 1;
}


//��ջSΪ��ջ��ջ��ָ���ջ��ָ����ͬ��, �򷵻�1�����򷵻�0
int StackEmpty1(SqStack1 *S)
{
    if (S->top == S->base)
        return 1;
    else
        return 0;
}


//����Ԫ��eΪ�µ�ջ��Ԫ��
int Push(SqStack1 *S, SElemType e)
{
    if ((*S).top - (*S).base >= (*S).stacksize1)
    {
        (*S).base = (SElemType *)realloc((*S).base, ((*S).stacksize1 + STACKINCREMENT1) * sizeof(SElemType));
        if (!(*S).base)
            exit(0);
        (*S).top = (*S).base + (*S).stacksize1;
        (*S).stacksize1 += STACKINCREMENT1;
    }
    *((*S).top)++ = e;
    return 1;
}


//��ջ��Ϊ�գ���ɾ��Sջ��Ԫ����e������ֵ��������1�����򷵻�0
int Pop(SqStack1 *S, SElemType *e)
{
    if ((*S).top == (*S).base)
    {
        return 0;
    }
    *e = *--(*S).top;
    return 1;
}
//����ͼ����������
void TopologicalSort(MGraph G)
{
    int i,k;
    int count = 0;
    SqStack1 S;
    InitStack1(&S);
    for (i = 0; i<G.vexnum; i++)
    {
        if (G.in[i] == 0)
        {
            Push(&S, i);
        }
    }
    while (!StackEmpty1(&S))
    {
        Pop(&S, &k);
        printf("%c->", G.vers[k]);
        count++;
        for (i = 0; i < G.vexnum; i++)
        {
            if (G.arcs[k][i].adj == 1)
            {
                G.in[i]--;
                if (G.in[i] == 0)
                {
                    Push(&S, i);
                }
            }
        }
    }
    //�������õ�����������Ľڵ���ĿС���ܵģ�˵��������ͨͼ
    if (count < G.vexnum)
    {
        printf("��ͼ���л�·��\n");
    }
    else
    {
        printf("��ͼ��û�л�·��\n");
    }

}

int main()
{
	
	return 0;
}