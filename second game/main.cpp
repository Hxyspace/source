#include <graphics.h>
#include <conio.h>
#pragma comment(lib,"winmm.lib")
#include <time.h>
#include <stdlib.h>

#define up 72
#define down 80
#define left 75
#define right 77

#define Length 600              //页面大小
#define Width 440
#define size 10                //蛇身大小

typedef struct QNode
{
	int x,y;
	struct QNode *next;
}QNode,*QueuePrt;

typedef struct
{
	QueuePrt front,rear;
} LinkQueue;

struct FOOD
{
	int x,y;
} food;

IMAGE Backdrop,Food,BFood,Pay,pay;               //定义图片变量
char ch = 0;
int Init = 0,Init1 = 1;
int i = 3,j = 0,n = 3;

void begin();
void map();
LinkQueue initQueue();
QNode* InitQNode();
void InsertQueue(LinkQueue *q,QNode *P);
void OutQueue(LinkQueue q);
void initSnake(LinkQueue *q);
void run(LinkQueue *q);
void change();
void showfood();
void getfood(LinkQueue Q);
bool Repeat(LinkQueue Q);
bool over(LinkQueue Q);
bool eatfood(LinkQueue *Q);
void set();
void Grade();
void overshow();

int main()
{
	LinkQueue Q;
	Q = initQueue();
	initSnake(&Q);
	initgraph(Length,Width);
	setbkcolor(CYAN);
	mciSendString(L"open 鼠标点击.wav alias Beel", 0, 0, 0); 
	mciSendString(L"open TakeMeHand.mp3 alias BGM", 0, 0, 0); 
	mciSendString(L"open 开始.mp3 alias begin", 0, 0, 0); 
	begin();
	mciSendString(L"play begin", 0, 0, 0);
	_sleep(500);
	loadimage(&Backdrop,L"纸盒人.jpg");
	loadimage(&Pay,L"Pay.jpg",100,100);
	loadimage(&pay,L"Pay.jpg",200,200);
	loadimage(&Food,L"甜甜圈.bmp",size+5,size+5);
	loadimage(&BFood,L"甜甜圈掩码.bmp",size+5,size+5);
	mciSendString(L"play BGM repeat", 0, 0, 0);
	map();
	getfood(Q);
	while(1)
	{
	while (!kbhit())
	{
	BeginBatchDraw();
	putimage(11,11,419,419,&Backdrop,11,11);
	OutQueue(Q);
	eatfood(&Q);
	showfood();
	Grade();
	if(ch)
	run(&Q);
	EndBatchDraw();
	_sleep(i*i*30+20);
	}
	change();
	}
	return 0;
}

void begin()
{
	MOUSEMSG mouse;
	mouse = GetMouseMsg();
	int a = 0,b = 0,c = 0,d = 0;       //用于标记字体是否被放大
	//clock_t start,finish;              //定义时间变量
	setbkmode(TRANSPARENT);
	while(1)
	{
	BeginBatchDraw();
	if(MouseHit())
		mouse = GetMouseMsg();
	cleardevice();
	
	if(Init==0 && mouse.x>Length/2-50 && mouse.x<Length/2+50 && mouse.y>Width/2-100 && mouse.y<Width/2-50 )         //如果鼠标在字的内部，则放大字体
	{
		settextstyle(70,0,L"方正舒体");
		outtextxy(Length/2-60,Width/2-110,L"开始");
		a = 1;
		if(Init1)
		{
			mciSendString(L"open 鼠标点击.wav alias Beel", 0, 0, 0); 
			mciSendString(L"play Beel ", NULL,0,NULL); 
			//start = clock();
			Init1 = 0;
		}
		if(mouse.mkLButton)
		{
			EndBatchDraw();
			break;
		}

	}
	else
	{
		settextstyle(50,0,L"方正舒体");
		outtextxy(Length/2-50,Width/2-100,L"开始");
		a = 0;
	}
	if(Init==0 && mouse.x>Length/2-200 && mouse.x<Length/2-100 && mouse.y>Width/2-50 && mouse.y<Width/2 )
	{
		settextstyle(70,0,L"方正舒体");
		outtextxy(Length/2-210,Width/2-60,L"设置");
		b = 1;
		if(Init1)
		{
			mciSendString(L"open 鼠标点击.wav alias Beel", 0, 0, 0); 
			mciSendString(L"play Beel ", NULL,0,NULL); 
			//start = clock();
			Init1 = 0;
		}
		if(mouse.mkLButton)
		{
			EndBatchDraw();
			set();
			mouse = GetMouseMsg();
		}
		
	}
	else
	{
		settextstyle(50,0,L"方正舒体");
		outtextxy(Length/2-200,Width/2-50,L"设置");
		b = 0;
	}

	if(Init==0 && mouse.x>Length/2+50 && mouse.x<Length/2+150 && mouse.y>Width/2 && mouse.y<Width/2+50 )
	{
		settextstyle(70,0,L"方正舒体");
		outtextxy(Length/2+40,Width/2-10,L"退出");
		c = 1;
		if(Init1)
		{
			mciSendString(L"open 鼠标点击.wav alias Beel", 0, 0, 0); 
			mciSendString(L"play Beel ", NULL,0,NULL); 
			//start = clock();
			Init1 = 0;
		}
		if(mouse.mkLButton)
		{
			EndBatchDraw();
			exit(0);
		}
	}
	else
	{
		settextstyle(50,0,L"方正舒体");
		outtextxy(Length/2+50,Width/2,L"退出");
		c = 0;
	}
	//finish = clock();
	if(!a&&!b&&!c)
	{
		if(Init1==0)
		//if((double)(finish-start)/CLOCKS_PER_SEC > 1)
		{
			mciSendString(L"close Beel", NULL,0,NULL);
		Init1 = 1;
		}
	}

	EndBatchDraw();
	}
}

QNode* InitQNode()
{
	QNode *p;
	p = (QueuePrt)malloc(sizeof(QNode));
	p->next = NULL;
	return p;
}

LinkQueue initQueue()               //初始化队头队尾指针
{
	LinkQueue q;
	q.front = q.rear = (QueuePrt)malloc(sizeof(QNode));
	if(!q.front)
		exit(0);
	q.front->next = NULL;
	return q;
}

void InsertQueue(LinkQueue *q,QueuePrt P)     //入队
{
	QueuePrt p;
	p = P;
	q->rear->next = p;
	q->rear = p;
}

void OutQueue(LinkQueue Q)                //打印蛇
{
	QueuePrt p;
	LinkQueue q;
	q = initQueue();
	q.front->next = Q.front->next;
	q.rear = Q.rear;
	p = q.front->next;
	setlinecolor(YELLOW);
	setfillcolor(GREEN);
	fillcircle (p->x*size+(size/2)+3,p->y*size+(size/2)+3,(int)(0.6*size));
	q.front->next = p->next;
	while(q.front->next)
	{
		p = q.front->next;
		fillrectangle (p->x*size+3,p->y*size+3,p->x*size+size+3,p->y*size+size+3);
		q.front->next = p->next;
	}
	setfillcolor(RED);
	fillcircle (p->x*size+(size/2)+3,p->y*size+(size/2)+3,(int)(0.8*size));
	free(q.front);
	if(over(Q))
	overshow();

}

void initSnake(LinkQueue *q)                 //初始化蛇
{
	QueuePrt a,b,c;
	srand((unsigned int)time(NULL));
	a = InitQNode();
	b = InitQNode();
	c = InitQNode();
	a->x = rand()%(Width/size - 10)+3;
	a->y = rand()%(Width/size - 10)+3;
	b->x = a->x + 1;
	b->y = a->y;
	c->x = b->x+1;
	c->y = b->y;
	InsertQueue(q,a);
	InsertQueue(q,b);
	InsertQueue(q,c);
}

void map()                        //初始地图页面
{
	int i;
	putimage(0,0,&Backdrop);      //绘制背景
	for(i=0;i<44;i++)
	{
		setfillcolor(BLUE);
		fillrectangle (i * 10,0 ,i * 10 +10 , 10);
		fillrectangle ( 0 ,i * 10 ,10 , i * 10 +10);
		_sleep(50);
	}
	for(i=0;i<44;i++)
	{
		fillrectangle (i * 10,430,i * 10 +10 ,430+10);
		fillrectangle ( 430 ,i * 10 ,430+10 , i * 10 +10);
		_sleep(50);
	}
	solidrectangle(441,0,600,10);
	for(i=2;i<87;i++)
	{
		setfillcolor(BLUE);
		solidrectangle (590,i * 5,600,i * 5 + 5);
		setfillcolor(BLACK);
		solidrectangle(441,i * 5,590,i * 5 + 5);
		_sleep(5);
	}
	setfillcolor(BLUE);
	solidrectangle(441,430,600,440);

}

void change()
{
	char move;
		move = _getch();
		switch (move)
		{
			case up:
				if(ch!=down)
					ch = move;break;
			case down:
				if(ch!=up)
					ch = move;break;
			case right:
				if(ch!=left)
					ch = move;break;
			case left:
				if(ch!=right)
					ch = move;break;
		}
}

void run(LinkQueue *q)
{
	QueuePrt p;
	
	p = q->front->next;
	q->front->next = p->next;
	
	switch (ch)
	{
	case up:
		p->x = q->rear->x;p->y = q->rear->y-1;break;
	case down: 
		p->x = q->rear->x;p->y = q->rear->y+1;break;
	case right:
		p->x = q->rear->x+1;p->y = q->rear->y;break;
	case left:
		p->x = q->rear->x-1;p->y = q->rear->y;break;
	}
	p->next=NULL;
	InsertQueue(q,p);
	
}

void showfood()                        //画食物
{
	putimage(food.x*size,food.y*size,&BFood,SRCAND);             //掩码图
	putimage(food.x*size,food.y*size,&Food,SRCPAINT);
	
}

void getfood(LinkQueue Q)
{
	srand((unsigned int)time(NULL));
	food.x = rand()%(Width/(size)-4)+1;
	food.y = rand()%(Width/(size)-4)+1;
	while(Repeat(Q))
	{
		food.x = rand()%(Width/(size)-4)+1;
		food.y = rand()%(Width/(size)-4)+1;
	}

}

bool Repeat(LinkQueue Q)               //判断生成的食物是否与蛇重叠
{
	QueuePrt p;
	LinkQueue q;
	q = initQueue();
	q.front->next = Q.front->next;
	q.rear = Q.rear;
	while(q.front->next)
	{
		p = q.front->next;
		if (p->x==food.x&&p->y==food.y)
		{
			free(q.front);
			return TRUE;
		}
		q.front->next = p->next;
	}
	free(q.front);
	return FALSE;
}

bool eatfood(LinkQueue *Q)             //吃到食物
{
	if(Q->rear->x == food.x && Q->rear->y == food.y)
	{
		QueuePrt p;
		p = InitQNode();
		p->x = Q->front->next->x;
		p->y = Q->front->next->y;
		p->next = Q->front->next;
		Q->front->next=p;
		getfood(*Q);
		n++;
		return TRUE;
	}
	return FALSE;
}

void set()
{
	MOUSEMSG mouse;
	mouse = GetMouseMsg();
	TCHAR s[4][9] = {_T("<< 恶魔 >>"),_T("<< 困难 >>"),_T("<< 一般 >>"),_T("<< 简单 >>")};
	TCHAR a[2][8] = {_T("<< 开 >>"),_T( "<< 关 >>")};
	getbkmode();
	while(1)
	{
	if(MouseHit())
	mouse = GetMouseMsg();
	BeginBatchDraw();
	cleardevice();
	settextstyle(50,0,L"微软雅黑");
	outtextxy(Length/4,Width/4,L"难度");
	outtextxy(Length/4,Width/4+80,L"声音");
	outtextxy(Length/4+200,Width/4,s[i]);
	outtextxy(Length/4+225,Width/4+80,a[j]);
	if(mouse.x>Length/4+200 && mouse.x<Length/4+250 && mouse.y>Width/4 && mouse.y<Width/4+50 && mouse.mkLButton)
	{
		i++;
		if(i==4)
			i = 0;
		_sleep(200);
	}
	if(mouse.x>Length/4+350 && mouse.x<Length/4+400 && mouse.y>Width/4 && mouse.y<Width/4+50 && mouse.mkLButton)
	{
		i--;
		if(i==-1)
			i = 3;
		_sleep(200);
	}
	if(mouse.x>Length/4+225 && mouse.x<Length/4+275 && mouse.y>Width/4+80 && mouse.y<Width/4+130 && mouse.mkLButton)
	{
		j--;
		if(j==-1)
			j = 1;
		_sleep(200);
	}
	if(mouse.x>Length/4+325 && mouse.x<Length/4+375 && mouse.y>Width/4+80 && mouse.y<Width/4+130 && mouse.mkLButton)
	{
		j++;
		if(j==2)
			j = 0;
		_sleep(200);
	}
	if(mouse.x>Length/4+100 && mouse.x<Length/4+200 && mouse.y>Width/4+160 && mouse.y<Width/4+210)
	{
		settextstyle(60,0,L"微软雅黑");
		outtextxy(Length/4+95,Width/4+155,L"确定");
		if(mouse.mkLButton)
		{   EndBatchDraw();
			break;
		}
	}
	else
	outtextxy(Length/4+100,Width/4+160,L"确定");
	EndBatchDraw();
	}
}

void Grade()
{
	TCHAR s[4][4] = {_T("恶魔"),_T("困难"),_T("一般"),_T("简单")};
	TCHAR a[9];
	_stprintf(a, _T("%d"),n);
	setfillcolor(BLACK);
	fillrectangle(441,10,590,Width-9);
	settextcolor(WHITE);
	settextstyle(25,0,L"微软雅黑");
	outtextxy(520,100,s[i]);
	outtextxy(460,100,L"难度");
	outtextxy(460,50,L"长度");
	outtextxy(520,50,a);
	outtextxy(450,300,L"复活币");
	outtextxy(520,300,L"0");
	settextstyle(20,0,L"黑体");
	outtextxy(450,260,L"扫码充值复活币");
	putimage(460,150,&Pay);
}

bool over(LinkQueue Q)               
{
	QueuePrt p,P;
	LinkQueue q;
	P = InitQNode();
	q = initQueue();
	q.front->next = Q.front->next;
	q.rear = Q.rear;
	P->x = q.rear->x;
	P->y = q.rear->y;
	while(q.front->next->next)
	{
		p = q.front->next;
		if (p->x==P->x&&p->y==P->y)
		{
			free(P);
			free(q.front);
			return TRUE;
		}
		q.front->next = p->next;
	}
	if(P->x<1||P->y<1||P->x>41||P->y>41)
		{
			free(P);
			free(q.front);
			return TRUE;
		}
	free(q.front);
	return FALSE;
}

void overshow()
{
	EndBatchDraw();
	mciSendString(L"close all",0,0,0);
	mciSendString(L"open PayVoice.wav alias Pay",NULL, 0, NULL); 
	BeginBatchDraw();
	putimage(100,50,&pay);
	settextcolor(BLACK);
	settextstyle(30,0,L"微软雅黑");
	outtextxy(100,300,L"你复活币数量为0");
	outtextxy(80,350,L"扫码付款可购买复活币");
	EndBatchDraw();
	_sleep(5000);
	mciSendString(L"play Pay",NULL, 0, NULL);
	setfillcolor(WHITE);
	solidrectangle(11,140,429,200);
	settextcolor(RED);
	settextstyle(40,0,L"方正舒体");
	outtextxy(50,150,L"付款成功  请稍后...");
	_sleep(5000);
	setfillcolor(GREEN);
	settextcolor(BLACK);
	solidrectangle(11,11,429,429);
	outtextxy(130,100,L"Sorry!!!");
	outtextxy(50,150,L"复活功能尚未完善");
	outtextxy(50,200,L"您所支付的金额将");
	outtextxy(65,240,L"在7个工作日内");
	outtextxy(60,280,L"退还到您的账户");
	setfillcolor(BLACK);
	solidrectangle(445,300,580,400);
	settextcolor(WHITE);
	settextstyle(25,0,L"微软雅黑");
	outtextxy(450,300,L"复活币");
	outtextxy(520,300,L"999");
	while(1);
}