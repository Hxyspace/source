
/*����
789,897,978,789......��ÿ����ǰһ������λ�����λ��������
ǰ999���
*/
#include<stdio.h>

int main()
{
	int sum = 0,n,i;
	n = 789;
	for(i = 1;i<=999;i++)
	{
		sum += n;
		n = (n%100)*10 + n/100;
	}
	printf("%d\n",sum);
	getchar();
	return 0;
}