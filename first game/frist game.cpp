/************************************************************
*************       name:  "碰碰碰"             *************
********  ver 2.0                     作者：xin  ************
*************************************************************/

/** 本次修改：
	 
     1.新增死亡判定
	 2.新增结束页面
	 3.新增图标
	 4.加入速度
	 5.修复已知bug

	                             最后修改时间 2018.09.30   **/

#include <graphics.h>
#include <time.h>      //时间函数要用到
#pragma comment(lib,"winmm.lib")    //播放音乐要用
#include <conio.h>
#define Length 670                      //宏定义页面长宽
#define Width 446

IMAGE person,Eperson,Zhihe;                   //定义图片变量
int x,y;
int t = 500000;
int a[3] = {1,470,1},b[3] = {1,50,360},c[3] = {0,0,0},d[3],e[3];
clock_t start,finish;                   //定义时间变量
struct Sand                            //矩形结构体
{
	int x;
	int y;
	int x1;
	int y1;
};

void send_e();
void change(int *,int *,int *,int *,int *,Sand *);
int peng(Sand sand1,Sand sand2);
void begin();
void Over();

void init()
{
	//画页面和小黄人
	
	BeginBatchDraw();                                //批量画图函数 ，与底下的EndBatchDraw() 配对
	//cleardevice();                                     //清屏
	//setfillcolor(BROWN);                               //设置页面颜色
	//fillrectangle (0,0,Length,Width);                  //画矩形
	putimage(0,0,&Zhihe);
	putimage(x-25,y-25,&Eperson,SRCAND);                 //显示图片
	putimage(x-25,y-25,&person,SRCPAINT);

	send_e();
	
	EndBatchDraw();
	
}

int main()
{
	
	MOUSEMSG mouse;                             //定义鼠标变量

	initgraph(Length,Width);                    //初始化图形界面
	loadimage(&Zhihe,L"纸盒人.bmp");
	loadimage(&person,L"小黄人.bmp");                   //加载图片
	loadimage(&Eperson,L"小黄人隐.bmp");
	begin();
	start = clock();
	mciSendString(L"open 音乐.mp3 alias BGM", 0, 0, 0);   //打开音乐
	mciSendString(L"play BGM repeat", 0, 0, 0);           //repeat： 循环播放

	
	mouse = GetMouseMsg();                      //获取鼠标信息
	//将鼠标的坐标赋值给x,y
	x = mouse.x;
	y = mouse.y;
	setfillcolor(BROWN);
	fillrectangle (0,0,Length,Width);
	while(1)                         //不断清屏画图，实现动画效果
	{

	init();                      
	if(MouseHit())               //判断是否有鼠标信息
	{
	mouse = GetMouseMsg();
	}
	x = mouse.x;
	y = mouse.y;
	FlushMouseMsgBuffer();
	  if(0)
	   {
		   mciSendString(L"close BGM", 0, 0, 0);
		   cleardevice(); 
		   settextcolor(RED);
		   setbkmode(TRANSPARENT);
		   settextstyle(70,0,L"方正舒体");
		   outtextxy(70,140,L"OVER GAME");
		   while (1);
	   }
	}

	return 0;
}

void send_e()
{
	Sand sand[4];             //定义3个矩形  和一个小黄人的结构体
	int T;
	t = t - 100;
	T = t;
	if(t<0)
		T = 0;
	sand[3].x = x-18; sand[3].y = y-24;
	sand[3].x1 = x+18; sand[3].y1 = y+24;
	   //改变三个矩形的属性
	   change(a,b,c,d,e,sand);
	   sand[0].x1 = sand[0].x+50; sand[0].y1 = sand[0].y+40;
	   change(a+1,b+1,c+1,d+1,e+1,sand+1);
	   sand[1].x1 = sand[1].x+45; sand[1].y1 = sand[1].y+60;
	   change(a+2,b+2,c+2,d+2,e+2,sand+2);
	   sand[2].x1 = sand[2].x+55; sand[2].y1 = sand[2].y+55;

	   //判断三个三角形是否互撞
	   if(peng(sand[0],sand[1]))
	   { 
		   c[0]=1+(1+c[0]%4)%4;c[1]=1+(1+c[1]%4)%4;
		   if(d[0]==d[1])  e[0]=1+(e[0])%2;
	   }
	   if(peng(sand[0],sand[2]))
	   { 
		   c[0]=1+(1+c[0]%4)%4;c[2]=1+(1+c[2]%4)%4;
	       if(d[0]==d[2])  e[0]=1+e[0]%2;
	   }
	   if(peng(sand[2],sand[1]))
	   { 
		   c[2]=1+(1+c[2]%4)%4;c[1]=1+(1+c[1]%4)%4;
		   if(d[2]==d[1])  e[1]=1+e[1]%2;
	   }
  
	   //画三个矩形
		setfillcolor(BLUE);      //填充矩形的颜色
	    fillrectangle (sand[0].x,sand[0].y,sand[0].x1,sand[0].y1);

		setfillcolor(BLACK);
	    fillrectangle (sand[1].x,sand[1].y,sand[1].x1,sand[1].y1);

		setfillcolor(WHITE);
		fillrectangle (sand[2].x,sand[2].y,sand[2].x1,sand[2].y1);

		 if(peng(sand[0],sand[3])||peng(sand[1],sand[3])||peng(sand[2],sand[3]))
	   {
		   Over();
	   }
		 while(T--);

}

void change(int *a,int *b,int *c,int *d,int *e,Sand *sand)
{
	//尝试了数次 反射角 反弹 失败！，最终决定采用随机反弹，，后期会改善

	srand((unsigned int)time(NULL));                   //设置随机数种子

	if(*b+50>=Width) *c = 1,*e = 1+(1+rand()%2)%2;
	else if(*a+50>=Length) *c = 2,*e = 1+(rand()%2)%2;
	else if(*b<=0) *c = 3,*e = 1+(1+rand()%2)%2;
	else if(*a<=0) *c = 4,*e = 1+(rand()%2)%2;
	
	if (*c == 0)
	{
		*e = 2;
		*a+=2;*b+=1; *d = 1;
	}
	else if(*c==1)
	{
	 
		switch(*e)
		{
		case 1:*a-=2;*b-=1;*d = 2;break;
		case 2:*a+=1;*b-=2;*d = 3;break;
		}

	}
	else if(*c==2)
	{
		
		switch(*e)
		{
		case 1:*a-=2;*b-=1;*d = 2;break;
		case 2:*a-=1;*b+=2;*d = 4;break;
		}

	}
	else if(*c==3)
	{
	
		switch(*e)
		{
		case 1:*a-=1;*b+=2;*d = 4;break;
		case 2:*a+=2;*b+=1;*d = 1;break;
		}

	}
	else if(*c==4)
	{
	
		switch(*e)
		{
		case 1:*a+=1;*b-=2;*d = 3;break;
		case 2:*a+=2;*b+=1;*d = 1;break;
		}

	}

		sand->x= *a;sand->y = *b;

}

int peng(Sand sand1,Sand sand2)             //判断三个矩形是否互撞
{


	if( (sand1.x>=sand2.x&&sand1.x<=sand2.x1&&sand1.y>=sand2.y&&sand1.y<=sand2.y1)
		||(sand1.x1>=sand2.x&&sand1.x1<=sand2.x1&&sand1.y>=sand2.y&&sand1.y<=sand2.y1)
		||(sand1.x>=sand2.x&&sand1.x<=sand2.x1&&sand1.y1>=sand2.y&&sand1.y1<=sand2.y1)
		||(sand1.x1>=sand2.x&&sand1.x1<=sand2.x1&&sand1.y1>=sand2.y&&sand1.y1<=sand2.y1)
		||(sand1.x>=sand2.x&&sand1.x<=sand2.x1&&sand2.y>=sand1.y&&sand2.y<=sand1.y1)
		||(sand1.x>=sand2.x&&sand1.x<=sand2.x1&&sand2.y1>=sand1.y&&sand2.y1<=sand1.y1)
		||(sand1.x1>=sand2.x&&sand1.x1<=sand2.x1&&sand2.y>=sand1.y&&sand2.y<=sand1.y1)
		||(sand1.x1>=sand2.x&&sand1.x1<=sand2.x1&&sand2.y1>=sand1.y&&sand2.y1<=sand1.y1)
		||(sand2.x>=sand1.x&&sand2.x<=sand1.x1&&sand1.y>=sand2.y&&sand1.y<=sand2.y1)
		||(sand2.x1>=sand1.x&&sand2.x1<=sand1.x1&&sand1.y>=sand2.y&&sand1.y<=sand2.y1)
		||(sand2.x>=sand1.x&&sand2.x<=sand1.x1&&sand1.y1>=sand2.y&&sand1.y1<=sand2.y1)
		||(sand2.x1>=sand1.x&&sand2.x1<=sand1.x1&&sand1.y1>=sand2.y&&sand1.y1<=sand2.y1))
		   return 1;
	else return 0;

}



void begin()
{
	MOUSEMSG E;
	mciSendString(L"open 开始.mp3 alias B", 0, 0, 0);   //打开音乐
	
	setfillcolor(BROWN);
	fillrectangle (0,0,Length,Width);
	fillrectangle (250,170,390,230);
	setbkmode(TRANSPARENT);
	settextstyle(70,0,L"方正舒体");
	outtextxy(250,160,L"开始");
	while(1)
	{
		BeginBatchDraw();
		E = GetMouseMsg();
		if(E.x>=250&&E.x<=390&&E.y>=170&&E.y<=230)
		{
			
			setfillcolor(RED);
			fillrectangle (250,170,390,230);
			setbkmode(TRANSPARENT);
			settextstyle(70,0,L"方正舒体");
			outtextxy(250,160,L"开始");
			
			if(E.mkLButton)
			{
				mciSendString(L"play B ", 0, 0, 0);
				_sleep(1000);
			break;
			}
				
		}
		else
		{
			setfillcolor(BROWN);
			fillrectangle (250,170,390,230);
			setbkmode(TRANSPARENT);
			settextstyle(70,0,L"方正舒体");
			outtextxy(250,160,L"开始");
		}
		EndBatchDraw();
		
	}
}

void Over()
{
	EndBatchDraw();
		   finish = clock();
		   _sleep(1000);
		   mciSendString(L"close BGM", 0, 0, 0);
		   cleardevice(); 
		   settextcolor(RED);
		   setbkmode(TRANSPARENT);
		   settextstyle(70,0,L"方正舒体");
		   outtextxy(160,160,L"OVER GAME");
		   _sleep(1000);
		   TCHAR s[9];
		   _stprintf(s, _T("%0.4lf"),(double)(finish-start)/CLOCKS_PER_SEC);        // 高版本 VC 推荐使用 _stprintf_s 函数
		   cleardevice(); 
		   settextcolor(YELLOW);
		   settextstyle(40,0,L"方正舒体");
		   outtextxy(200,100,L"你的成绩是：");
		   settextcolor(GREEN);
		   settextstyle(65,0,L"方正舒体");
		   outtextxy(210,160,s);
		   settextcolor(RED);
		   outtextxy(400,160,L"秒");
		   settextstyle(20,0,L"黑体");
		   outtextxy(350,250,L"小伙子，不行呀。哈哈哈");

		   settextcolor(BLACK);
		   setfillcolor(GREEN);
			fillrectangle (0,0,90,30);
			settextstyle(20,0,L"黑体");
			outtextxy(5,5,L"重新开始");

			setfillcolor(RED);
			fillrectangle (Length-50,0,Length,30);
			settextstyle(20,0,L"黑体");
			outtextxy(Length-45,5,L"退出");

			
			while(1)
			{
				MOUSEMSG mouse;
				mouse = GetMouseMsg();
				if(kbhit())
				{
					if(getch() == 'a')
					{
						cleardevice();
						settextcolor(WHITE);
						settextstyle(35,0,L"方正舒体");
						outtextxy(240,80,L"大...大佬！");
						outtextxy(180,115,L"不好意思！算错了！！");
						settextcolor(YELLOW);
						outtextxy(200,160,L"你的成绩是：");
						settextcolor(GREEN);
						settextstyle(65,0,L"方正舒体");
						outtextxy(210,230,L"1.356");
						settextstyle(65,0,L"微软雅黑");
						settextcolor(RED);
						outtextxy(350,230,L"小时");

						settextcolor(BLACK);
						setfillcolor(GREEN);
						fillrectangle (0,0,90,30);
						settextstyle(20,0,L"黑体");
						outtextxy(5,5,L"重新开始");

						setfillcolor(RED);
						fillrectangle (Length-50,0,Length,30);
						settextstyle(20,0,L"黑体");
						outtextxy(Length-45,5,L"退出");
					}
				}
				if(mouse.x>Length-50&&mouse.x<Length&&mouse.y>0&&mouse.y<30)
				{
					settextcolor(RED);
					setfillcolor(BLACK);
						fillrectangle (Length-50,0,Length,30);
						settextstyle(20,0,L"黑体");
						outtextxy(Length-45,5,L"退出");
					if(mouse.mkLButton)
						exit(1);
				}
			}
		   
		  // while(1);
}