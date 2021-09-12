//将三个无序的数从大到小输出
#include<stdio.h>          
int main()
{
int a=0;   int b=0; 
int c=0;   int i=0;
scanf("%d%d%d",&a,&b,&c);
 if(a<b)     //因为下面是按a,b,c的顺序打印的
{               //则若a>=b,就是按照(a,b,c)的顺序,不要考虑
  i=a;       //将b的值赋给a,则a的值会被覆盖
               //没有值可以赋给b,那么可以创建一个变量i先存放a的值
  a=b;     //再对a进行修改,之后把i的值赋给现在的b
  b=i;
}
 if(a<c)      //因为下面是按a,b,c的顺序打印的
{               //则若a>=c,就是按照(a,b,c)的顺序,不要考虑
  i=a;
  a=c;
  c=i;
}
 if(b<c)     //因为下面是按a,b,c的顺序打印的
{              //则若b>=c,就是按照(a,b,c)的顺序,不要考虑
  i=b;
  b=c;
  c=i;
}
printf("%d %d %d",a,b,c);
return 0;
}            
