/************************************************************
*************       name:  "������"             *************
********  ver 2.0                     ���ߣ�xin  ************
*************************************************************/

/** �����޸ģ�
	 
     1.���������ж�
	 2.��������ҳ��
	 3.����ͼ��
	 4.�����ٶ�
	 5.�޸���֪bug

	                             ����޸�ʱ�� 2018.09.30   **/

#include <graphics.h>
#include <time.h>      //ʱ�亯��Ҫ�õ�
#pragma comment(lib,"winmm.lib")    //��������Ҫ��
#include <conio.h>
#define Length 670                      //�궨��ҳ�泤��
#define Width 446

IMAGE person,Eperson,Zhihe;                   //����ͼƬ����
int x,y;
int t = 500000;
int a[3] = {1,470,1},b[3] = {1,50,360},c[3] = {0,0,0},d[3],e[3];
clock_t start,finish;                   //����ʱ�����
struct Sand                            //���νṹ��
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
	//��ҳ���С����
	
	BeginBatchDraw();                                //������ͼ���� ������µ�EndBatchDraw() ���
	//cleardevice();                                     //����
	//setfillcolor(BROWN);                               //����ҳ����ɫ
	//fillrectangle (0,0,Length,Width);                  //������
	putimage(0,0,&Zhihe);
	putimage(x-25,y-25,&Eperson,SRCAND);                 //��ʾͼƬ
	putimage(x-25,y-25,&person,SRCPAINT);

	send_e();
	
	EndBatchDraw();
	
}

int main()
{
	
	MOUSEMSG mouse;                             //����������

	initgraph(Length,Width);                    //��ʼ��ͼ�ν���
	loadimage(&Zhihe,L"ֽ����.bmp");
	loadimage(&person,L"С����.bmp");                   //����ͼƬ
	loadimage(&Eperson,L"С������.bmp");
	begin();
	start = clock();
	mciSendString(L"open ����.mp3 alias BGM", 0, 0, 0);   //������
	mciSendString(L"play BGM repeat", 0, 0, 0);           //repeat�� ѭ������

	
	mouse = GetMouseMsg();                      //��ȡ�����Ϣ
	//���������긳ֵ��x,y
	x = mouse.x;
	y = mouse.y;
	setfillcolor(BROWN);
	fillrectangle (0,0,Length,Width);
	while(1)                         //����������ͼ��ʵ�ֶ���Ч��
	{

	init();                      
	if(MouseHit())               //�ж��Ƿ��������Ϣ
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
		   settextstyle(70,0,L"��������");
		   outtextxy(70,140,L"OVER GAME");
		   while (1);
	   }
	}

	return 0;
}

void send_e()
{
	Sand sand[4];             //����3������  ��һ��С���˵Ľṹ��
	int T;
	t = t - 100;
	T = t;
	if(t<0)
		T = 0;
	sand[3].x = x-18; sand[3].y = y-24;
	sand[3].x1 = x+18; sand[3].y1 = y+24;
	   //�ı��������ε�����
	   change(a,b,c,d,e,sand);
	   sand[0].x1 = sand[0].x+50; sand[0].y1 = sand[0].y+40;
	   change(a+1,b+1,c+1,d+1,e+1,sand+1);
	   sand[1].x1 = sand[1].x+45; sand[1].y1 = sand[1].y+60;
	   change(a+2,b+2,c+2,d+2,e+2,sand+2);
	   sand[2].x1 = sand[2].x+55; sand[2].y1 = sand[2].y+55;

	   //�ж������������Ƿ�ײ
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
  
	   //����������
		setfillcolor(BLUE);      //�����ε���ɫ
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
	//���������� ����� ���� ʧ�ܣ������վ���������������������ڻ����

	srand((unsigned int)time(NULL));                   //�������������

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

int peng(Sand sand1,Sand sand2)             //�ж����������Ƿ�ײ
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
	mciSendString(L"open ��ʼ.mp3 alias B", 0, 0, 0);   //������
	
	setfillcolor(BROWN);
	fillrectangle (0,0,Length,Width);
	fillrectangle (250,170,390,230);
	setbkmode(TRANSPARENT);
	settextstyle(70,0,L"��������");
	outtextxy(250,160,L"��ʼ");
	while(1)
	{
		BeginBatchDraw();
		E = GetMouseMsg();
		if(E.x>=250&&E.x<=390&&E.y>=170&&E.y<=230)
		{
			
			setfillcolor(RED);
			fillrectangle (250,170,390,230);
			setbkmode(TRANSPARENT);
			settextstyle(70,0,L"��������");
			outtextxy(250,160,L"��ʼ");
			
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
			settextstyle(70,0,L"��������");
			outtextxy(250,160,L"��ʼ");
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
		   settextstyle(70,0,L"��������");
		   outtextxy(160,160,L"OVER GAME");
		   _sleep(1000);
		   TCHAR s[9];
		   _stprintf(s, _T("%0.4lf"),(double)(finish-start)/CLOCKS_PER_SEC);        // �߰汾 VC �Ƽ�ʹ�� _stprintf_s ����
		   cleardevice(); 
		   settextcolor(YELLOW);
		   settextstyle(40,0,L"��������");
		   outtextxy(200,100,L"��ĳɼ��ǣ�");
		   settextcolor(GREEN);
		   settextstyle(65,0,L"��������");
		   outtextxy(210,160,s);
		   settextcolor(RED);
		   outtextxy(400,160,L"��");
		   settextstyle(20,0,L"����");
		   outtextxy(350,250,L"С���ӣ�����ѽ��������");

		   settextcolor(BLACK);
		   setfillcolor(GREEN);
			fillrectangle (0,0,90,30);
			settextstyle(20,0,L"����");
			outtextxy(5,5,L"���¿�ʼ");

			setfillcolor(RED);
			fillrectangle (Length-50,0,Length,30);
			settextstyle(20,0,L"����");
			outtextxy(Length-45,5,L"�˳�");

			
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
						settextstyle(35,0,L"��������");
						outtextxy(240,80,L"��...���У�");
						outtextxy(180,115,L"������˼������ˣ���");
						settextcolor(YELLOW);
						outtextxy(200,160,L"��ĳɼ��ǣ�");
						settextcolor(GREEN);
						settextstyle(65,0,L"��������");
						outtextxy(210,230,L"1.356");
						settextstyle(65,0,L"΢���ź�");
						settextcolor(RED);
						outtextxy(350,230,L"Сʱ");

						settextcolor(BLACK);
						setfillcolor(GREEN);
						fillrectangle (0,0,90,30);
						settextstyle(20,0,L"����");
						outtextxy(5,5,L"���¿�ʼ");

						setfillcolor(RED);
						fillrectangle (Length-50,0,Length,30);
						settextstyle(20,0,L"����");
						outtextxy(Length-45,5,L"�˳�");
					}
				}
				if(mouse.x>Length-50&&mouse.x<Length&&mouse.y>0&&mouse.y<30)
				{
					settextcolor(RED);
					setfillcolor(BLACK);
						fillrectangle (Length-50,0,Length,30);
						settextstyle(20,0,L"����");
						outtextxy(Length-45,5,L"�˳�");
					if(mouse.mkLButton)
						exit(1);
				}
			}
		   
		  // while(1);
}