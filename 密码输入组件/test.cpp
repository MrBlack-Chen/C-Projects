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
		printf("����������:>");
		for (i = 0; i < 6; i++)
		{
			arr[i] = _getch();
			printf("*");
		}
		printf("\n��ȷ��(Y/N):>");
		if (_getch()== 'Y')
		{
			if (strcmp(arr, password) == 0)
			{
				printf("\n������ȷ\n");
				system("pause");
				break;
			}
			else
			{
			  printf("�������,����������\n");
			  flag++;
			}
		}
		else
		{
			printf("\nȡ��ȷ��\n");
			system("pause");
		}
	} while (flag<=3);
	return 0;
}