#include<stdio.h>
//利用辗转相除法来解决最大公约数问题                        
int main()            
{
int m=0;    int n=0;
int r=0;      int tmp=0;
scanf("%d%d",&m,&n);
if(m<n)      //此保证下面是拿较大值%较小值，但也可以不用这一保证
{            
 tmp=m;     //将n的值赋给m,则m的值会被覆盖
 m=n;         //没有值可以赋给n,那么可以创建一个变量tmp先存放m的值
 n=tmp      //再对m进行修改,之后把tmp的值赋给现在的n        
}
while(r=m%n)           
 {                  //当余数为0时,即n=r=0,不能%0,则循环结束
  m=n;         //如果有余数,说明没除尽,则不是最大公约数
  n=r;
  }
printf("%d",n);  //此时n就为最大公约数
return 0;
}            
       
            
            
            
            
            
                     
                                    
            
                       
            
                        
                               