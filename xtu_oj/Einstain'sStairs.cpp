#include <stdio.h>
int main(void)
{
	int i,answer;
	printf("����˹̹�����������:\n");
	printf("���һ����ÿһ����2��,���ʣ1�ף�\n");
	printf("���һ����ÿһ����3��,���ʣ2�ף�\n");
	printf("���һ����ÿһ����5��,���ʣ4�ף�\n");
	printf("���һ����ÿһ����6��,���ʣ5�ף�\n");
	printf("���һ����ÿһ����7��,���պ�һ��Ҳ��ʣ��\n");
	for(i=7;i<=200;i+=7)
	{
		if(i%2==1&&i%3==2&&i%5==4&&i%6==5)
		{
			answer=i;
			break;
		}
	}
	printf("\n���ǣ�������ݹ���%d��̨��!\n",answer);
}