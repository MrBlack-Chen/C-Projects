#include<stdio.h>
#include<string.h>            
int main()            
{
char password[20]={0}; int ch=0; 
int i=0;
printf("请输入密码:>");
scanf("%s",password); //password为数组,本质上是一个地址,则不需要加取地址符&                                   
while((i=getchar())!='\n')//当用scanf()函数时,由于按了回车键继续
{                         //则在输入缓冲区(输入函数存储输入数据的地方)会多出\n(换行)
  ;                       //而getchar()在读取时只要有字符就会读取
                          //则此时如果不将\n搞掉
}                         //则下面不会停下来等待输入Y\N
printf("请确认(Y/N):>");
ch=getchar();
if(ch=='Y')
 {
printf("确认成功…待验证\n");
  for(i=1;i<=3;i++)
  {
  //if(password=="888888") 左边的语句是错误的
                     //上面比较两个字符串相等不能用==
                     //而应该用库函数strcmp()，则需要引头文件<string.h>
                     //若相等则会返回0;前>后,则返回值大于0;前<后,则返回值小于0
    if(strcmp(password,"888888")==0)
    {  
       printf("密码正确\n");
       break;
    }
    else
    {
     printf("密码错误,请重新输入\n");
     printf("请输入密码:>");
     scanf("%s",password);
    }
   }
  if(i==3)
    printf("三次输入均错误，退出程序");
 }
else
printf("取消确认\n");
return 0;
}            

