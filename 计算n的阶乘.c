#include<stdio.h>                    
int main()            
{
  int n=0;   int i=0;
  int ret=1;  //ret不能赋值0,初始值要为1
                  //否则任何数*ret结果都为0
  scanf("%d",&n);     
  for(i=1;i<=n;i++)
  {
    ret=ret*i;  //拿之前的本身*i就构成了递乘
  }
  printf("阶乘=%d\n",ret);
  return 0;
}            