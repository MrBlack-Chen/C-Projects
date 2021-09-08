#include<stdio.h>
//ret循环后未初始化带来的积累的解决    
int main()            
{
  //1.可利用每次循环后将ret初始化为1      
  int i=0;       int n=0;
  int ret=1;   int sum=0;
for(n=1;n<=3;n++)
{            
  ret=1;  //可利用将ret进行初始化为1
             //来抵消下面的1*,2*的积累
  for(i=1;i<=n;i++)  15
   {                           //当每次循环后ret不初始化时(以n=3来举例，原本结果应为1!+2!+3!=9)                                                       
   ret=ret*i;            //i=1进来，ret变成1，当i++变成2>n=1,不满足则此次循环执行完毕
   }                         //回到主for的调整中,n变成2,再次进行判断,循环
  sum=sum+ret; //ret=1*1*2=2 则循环后不会销毁
                             //当n=3时,i又初始化为1,此时会执行三次副for循环
                            //ret=2*1*2*3=12
}                          //则最终sum=0+1=1+2=3+12=15错误
printf("%d\n",sum);

   //2.利用单层循环
int i=0;   int ret=1; 
int sum=0;
for(i=1;i<=3;i++)   //这样就避免了上面因for循环嵌套使用带来的问题
{                             //当i=1时满足,ret=1*1=1,sum=0+1=1
  ret=ret*i;             //i++变成2满足,ret=1*2=2,sum=1+2=3
  sum=sum+ret;   //i++变成3满足,ret=2*3=6,sum=3+6=9,输出 
}
printf("%d\n",sum);

return 0;
}                        
