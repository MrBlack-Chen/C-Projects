#include<stdio.h>
int main()            
{
int month=0;
scanf("%d",&month);
switch(month)
{
case 3:
case 4:
case 5:
  printf("春季\n");
break;     //break终止,跳出switch语句到return 0
              //防止继续运行其后的语句
case 6:
case 7:
case 8:
  printf("夏季\n");
break     //break终止,跳出switch语句到return 0
              //防止继续运行其后的语句
case 9:
case 10:
case 11:
  printf("秋季\n");
case 12:
case 1:
case 2:
printf("冬季\n");
break;    //break终止,跳出switch语句到return 0
              //防止继续运行其后的语句
default://default进行输入提示
printf("输入错误,请输入1～12月份");
break;    //break终止,跳出switch语句到return 0
              //防止继续运行其后的语句
}
return 0;
}            
