/* 企业发放的奖金根据利润提成。利润(i)低于或等于10万元时，奖金可提10%；利润高
于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可可提
成7.5%；20万到40万之间时，高于20万元的部分，可提成5%；40万到60万之间时高于
40万元的部分，可提成3%；60万到100万之间时，高于60万元的部分，可提成1.5%，高于
100万元时，超过100万元的部分按1%提成，从键盘输入当月利润i，求应发放奖金总数？ */
#include<iostream>

int main()
{
	int i;
	float sum = 0;
	std::cout<<"请输入利润(单位：万元)："<<std::endl;
	std::cin>>i;
	while(i<0)
	{
		std::cout<<"输入的数值非法，请重新输入："
		std::cin>>i;
	}
	sum += (i%10)*0.1 + (i%20)-;
	
	
	
	return 0;
}