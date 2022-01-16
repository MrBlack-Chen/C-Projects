#include<stdio.h>
#include<string.h>   
#include<conio.h>
#include<stdlib.h>

int main()
{
	char password[7] = "123456";
	char arr[7] = { 0 }; int flag=1;
	int i;
	do
	{
		printf("请输入密码:>");
		for (i = 0; i < 6; i++)
		{
			arr[i] = _getch();
			printf("*");
		}
		printf("\n请确认(Y/N):>");
		if (_getch()== 'Y')
		{
			if (strcmp(arr, password) == 0)
			{
				printf("\n密码正确\n");
				system("pause");
				break;
			}
			else
			{
			  printf("密码错误,请重新输入\n");
			  flag++;
			}
		}
		else
		{
			printf("\n取消确认\n");
			system("pause");
		}
	} while (flag<=3);
	return 0;
}