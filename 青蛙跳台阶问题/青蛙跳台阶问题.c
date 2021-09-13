//利用递归/循环解决青蛙跳台阶问题(类似斐波那契数列)
#include<stdio.h>
//第一种方法：利用递归
int jump1(int n)
{
 if(n<=2)
  return n;
 else
  return jump(n-1)+jump(n-2);
}       //当选择先跳一步时,剩下(n-1)步再跳
        //当选择先跳两步时,剩下(n-2)步再跳
        //剩下的依次递归下去 

//第二种方法：利用循环
int jump2(n)
{
 int a=1;
 int b=2;
 int c=0;
 if(n<=2)
  return n; //遇到return n就结束了程序（因为当台阶数为1时，只有一种跳法；当台阶数为2时，有两种跳法。即跳法数对应台阶数n）
 while(n>2) 
  {
   c=a+b;
   a=b;
   b=c;
   n--;
  }
 return c;
}
         
int main() 
{
int n=0;
printf("请输入台阶数 n=");
scanf("%d",&n);
int ret=jump1(n);
printf("总共跳法为：%d",ret);
return 0;
}                       
                             
