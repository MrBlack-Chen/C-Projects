#include<stdio.h>
#include<math.h>
int main()
{
 float a,b,c,d,x1,x2;
 printf("请输入二次项系数a：>");
 scanf("%f",&a);
 printf("\n请输入一次项系数b：>");
 scanf("%f",&b);
 printf("\n请输入常数项c：>");
 scanf("%f",&c);
 d=b*b-4*a*c;
  if(d<0)
   printf("\n该方程无解\n");
  else if(d==0)
   {
     if((-b)/2*a==0)
      printf("\n方程的解：x1=x2=%f",0);//防止出现-0的情况
     else
      printf("\n方程的解：x1=x2=%f",(-b)/2*a);
   }
   
  else
   printf("\n方程的解：x1=%f  x2=%f",(-b+sqrt(d))/(2*a),(-b-sqrt(d))/(2*a));
 return 0;
}

