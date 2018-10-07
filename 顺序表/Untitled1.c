#include <stdio.h>
#include <stdlib.h>         //申请内存时调用的malloc函数所在的库文件

#define MAXSIZE 100         //宏定义顺序表的最大长度
typedef int elemtype;       //将int类型取别称
typedef struct {            //定义顺序表结构体，并取别称为 sequenlist
	elemtype data[MAXSIZE];
	int last;
} sequenlist;

sequenlist * InitList()    //初始化
{
	sequenlist *L;                                //定义指向顺序表的指针
	L=(sequenlist *)malloc(sizeof(sequenlist));   //为顺序表申请内存
	L->last=0;                                    //初始化顺序元素为0
	return L;                                     //返回顺序表类型的指针
}
void InputList(sequenlist *L,int n) //追加n个数
{
	int i;
	if(L->last+n >MAXSIZE )                //判断追加n个数是否会超出顺序表空间
	{
		printf("超过空间！");
		return ;                           //退出此函数
	}
	printf("请输入%d个数:",n);
	for(i=0;i<n;i++)                               //输入n个数加入顺序表中
		scanf("%d" , &(L->data[L->last+i]));
	L->last=L->last+n;                             //表内数据个数加n
}

void ClearList(sequenlist *L)   //清空
{
	L->last=0;                  //直接把表内数据个数重置为0
}

int ListLength(sequenlist *L)   //计算长度
{
	return (L->last);           //表内数据的个数 就是顺序表长度    所以直接返回个数
}

int FindList(sequenlist *L,elemtype e)  //查找位置
{
	int i;
	for(i=0;i<L->last;i++)             //遍历顺序表
	{
		if(e==L->data[i])              //判断e是否与表中的某一数据相同
			return (i+1);              //返回e所在顺序表中的位置
	}
	printf("顺序表中不存在 [%d]\n",e); //如果上面遍历完整个顺序表仍然找不到e ，则表示e不在表中
	return 0;
}

int ListInsert(sequenlist *L,int i,elemtype e)   //插入数据
{
	int k;
	if (L->last == MAXSIZE )                     //判断顺序表是否已满
	{
		printf("顺序表已满，无法插入元素\n");
		return 0;
	}
	if (i<1||i>L->last+1)                        //判断插入的位置是否在顺序表范围内
	{
		printf("需要插入的位置不在顺序表范围中。\n");
		return 0;
	}
	if (i<=L->last)
	{
		for (k=L->last-1; k >= i-1;k--)
		{
			L->data[k+1] = L->data[k];             //插入的位置后面的元素都要向后移一位
		}
	}
	L->data[i-1] = e;                            //插入数据
	L->last++;                                   //长度加1
	return 1;
}

int GetElem(sequenlist *L,int i)    //取值
{
	int e;
	if(L->last == 0)                            //判断表是否为空
	{
		printf("顺序表为空\n");
		return 0;
	}
	if(i<1||i>L->last)                          //判断i是否在范围中
	{
		printf("第%d个位置超出顺序表范围\n",i);
		return 0;
	}
	return (L->data[i-1]);                 //返回第i个位置上的值
}

int ListDelete(sequenlist *L,int i)          //删除数据
{
	int k,e;
	if(L->last==0)                           //判断表是否为空
	{
		printf("顺序表为空表，无法执行删除操作。\n");
		return 0;
	}
	if(i<1||i>L->last)                       //判断i是否在范围中
	{
		printf("第%d个位置超出顺序表范围\n");
		return 0;
	}
	e = L->data[i-1];                        //将表中第i个元素赋值给e
	if(i<L->last)
	{
		for (k = i;k<L->last;k++)
		{
			L->data[k-1]=L->data[k];            //在所删除元素后面的元素位置都需向前移一位
		}
	}
	L->last--;                                 //长度减1
	printf("删除的元素为 [%d]\n",e);
	return 1;
}

void OutputList(sequenlist *L)
{
	int i;

	for(i=0;i<L->last;i++)              //遍历顺序表并将顺序表中元素打印出来
		printf("[%d] ",L->data[i]);
	printf("\n");
}

int Insert(sequenlist *L,elemtype e)   //有序插入
{
    int i,k;
    if (L->last == MAXSIZE )                  //判断顺序表是否已满
	{
		printf("顺序表已满，无法插入元素\n");
		return 0;
	}
    if(e<=L->data[0]||L->last==0)             //所插入数据比表中第一个数小  或者顺序表为空时  插入的数据直接放在第一位
    {
        for (k=L->last-1; k >=0;k--)
		{
			L->data[k+1] = L->data[k];        //后面的数据都向后面移一位
		}
	L->data[0] = e;                           //插在第一位
	L->last++;                                //长度加1

    }

    else if(e>=L->data[L->last-1])          //所插入数据比表中最后一个数大时
    {
        L->data[L->last]=e;                 //插入的数据放在最后一位
        L->last++;                          //长度加1

    }
	else                                   //数据需要插在中间时
    {
        for(i=1;i<=L->last-1;i++)          //遍历顺序表
            if(e<=L->data[i])              //比较插入的数据与表中元素的大小，比表中元素小时则跳出循环
            break;
		for (k=L->last-1; k >= i;k--)
		{
			L->data[k+1] = L->data[k];     //插入的位置后面的元素都向后移一位
        }
        L->data[i] = e;                    //插入数据
        L->last++;                         //长度加1
	}

	return 1;
}

void CreatList()         //执行有序插入函数
{
    int n,e;
    sequenlist L={{1,4,8,14,16,38,45,67,69,97,188,211},12};
    printf("顺序表L内数值为：\n");
    OutputList(&L);                            //显示表中各元素
    printf("请输入需要插入的元素：");
    scanf("%d",&n);                            //输入插入的元素
    Insert(&L,n);                              //调用有序插入的函数
    printf("插入成功，插入后的顺序表为：\n");
    OutputList(&L);                             //显示表中各元素



}

int LocateElem(sequenlist *L,elemtype e)  //查看某个数值是否在顺序表中
{
    int i;
    for(i=0;i<L->last;i++)
    {
        if(e==L->data[i])                //数值在表中存在  返回数值所在的位置
            return i+1;
    }
    return 0;                            //数值不在表中   返回 0
}

void unionL()              //合并两个顺序表
{
    sequenlist *La,*Lb;        //定义两个顺序表指针
    int La_len,Lb_len,i,e;
    La=InitList();              //调用初始化函数，初始化两个顺序表指针
    Lb=InitList();
    printf("请输入第一个线性表的数值，按回车结束输入。\n");

    do
    {
        scanf("%d",&e);
        Insert(La,e);         //调用有序插入函数，使输入的数值存进有序表中

    }while(getchar()!='\n');  //当输入不等于回车时循环

    printf("请输入第二个线性表的数值，按回车结束输入。\n");
    do
    {
        scanf("%d",&e);
        Insert(Lb,e);         //调用有序插入函数，使输入的数值存进有序表中

    }while(getchar()!='\n');  //当输入不等于回车时循环
    printf("两个顺序表分别为：\n");
    OutputList(La);                 //调用显示函数，将两个有序表显示出来
    OutputList(Lb);
	La_len = ListLength(La);        //调用求长度的函数，获取两个有序表的长度
	Lb_len = ListLength(Lb);
	for (i=1;i<=Lb_len;i++)
	{
		e=GetElem(Lb,i);            //将b有序表中的元素取出
//		if(!LocateElem(La,e))
//		{
			Insert(La,e);           //将取出的元素有序的插入a有序表中
//		}
	}
	printf("合并后的顺序表为：\n\n");
	OutputList(La);                   //显示合并后的有序表
}

int menu()   //菜单
{
	int choice;
	printf("  \n顺序表基本运算\n");
	printf("     1.追加\n");
	printf("     2.清空\n");
	printf("     3.计算长度\n");
	printf("     4.寻找的元素位置\n");
	printf("     5.插入元素\n");
	printf("     6.取值\n");
	printf("     7.删除\n");
	printf("     8.显示\n");
	printf("     9.有序插入\n");
	printf("     10.顺序表的合并\n");
	printf("     0.退出\n");
	printf("     请输入你的选择：");
	scanf("%d",&choice);
	return choice;                            //将用户输入的选择作为返回值
}

int main()
{
	int choice;
	sequenlist *L;             //定义顺序表指针
	int i,n;
	L=InitList();              //初始化顺序表


	do
	{
		choice=menu();         //调用菜单函数并将返回值赋值给choice
		printf("\n\n");
		switch(choice)         //根据用户输入的数值选择执行的功能
		{
		case 1:
			printf("要追加多少个数?");
			scanf("%d",&n);
			InputList(L,n);            //执行追加数据函数
			break;
		case 2:
			ClearList(L);               //执行清表函数
			printf("顺序表已清空\n\n");
			break;
		case 3:
			printf("顺序表的长度为%d\n\n",ListLength(L));   //调用求长度函数，并打印顺序表的长度
			break;
		case 4:
			printf("请输入要查找的值：\n");
			scanf("%d",&n);
			if(FindList(L,n))                                              //调用查找函数，并判断是否查找成功
				printf("[%d] 为顺序表中的第%d个数据\n",n,FindList(L,n));   //打印所查找元素所在的位置

			break;
		case 5:
			printf("请输入需要插入的位置：");
			scanf("%d",&i);
			printf("\n请输入需要插入的元素：");
			scanf("%d",&n);
			if(ListInsert(L,i,n))                         //调用插入函数，并判断是否插入成功
				printf("\n元素插入成功！\n");
			break;
		case 6:
			printf("需要取第几个位置的值？\n");
			scanf("%d",&i);
			if(GetElem(L,i))                                     //调用取值函数，并判断是否取值成功
				printf("第%d个位置的值为 [%d]",i,GetElem(L,i));  //打印取出来的元素
			break;
		case 7:
			printf("需要删除第几个位置的值？\n");
			scanf("%d",&i);
			ListDelete(L,i);                                //执行删除函数
			break;
		case 8:
			OutputList(L);                                  //执行显示函数
			break;
		case 9:
            CreatList();                                    //执行有序插入函数
			break;
        case 10:
            unionL();                                       //执行两个有序表的合并操作
		case 0:
			break;
		default:  printf("[ %d ]为非法项\n",choice);
		}
	}
	while(choice);                  //输入不为0时循环
	return 0;
}
