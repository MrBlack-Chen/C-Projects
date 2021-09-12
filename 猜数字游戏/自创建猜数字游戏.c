//创建猜数字游戏
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()//自创建菜单函数  
{
printf("********猜数字游戏********\n");
printf("**1.开始游戏  0.退出游戏**\n");
printf("**************************\n");
}
void game()//自创建游戏主体部分
{
int ret=0;  int input=0; int cnt=0;              
ret=rand()%100+1; //引用rand()生成随机数函数,生成的随机数%100的余数为0～99,+1之后得到1～100之间的数
while(1)//1为非0,表示真,while判断条件恒为真
 {
  printf("请猜数：>");
  scanf("%d",&input);
  if(input>ret)
  {
   printf("猜大了\n");
   cnt++;
  }
  else if(input<ret)
  {
   printf("猜小了\n");
   cnt++;
  }
  else
  {
  printf("恭喜你，猜对了\n");
  cnt++;
  break;
  }
 }
printf("猜测次数为：%d\n",cnt);
}          
int main()            
{
srand((unsigned int)time(NULL));//在引用rand()函数之前要先引用srand()设置生成随机数的起点
int i=0;                                         //设置一次即可,故不要放在game()里面,防止生成的数不随机           
menu();//引用菜单函数
do  //利用do…while()循环实现整个游戏的循环
{
printf("请选择：>");
scanf("%d",&i);
switch(i)
 {
  case 1:
   game();
   break;
  case 0:
   printf("退出游戏\n");
   break;
  default:
   printf("选择错误,请重新选择\n");
   break;
  }
}
while(i);  //while的判断条件为i的真假
               //0为假,1(非0)为真,则当输入1时会进入do再次游戏
              //当输入0时就不在进入do,结束了游戏
return 0;
}            
  
                              