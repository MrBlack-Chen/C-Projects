#include<stdio.h>
int check_sys()
{
 int a=1;
 return *(char*)&a;//强制类型转换成char*,则解引用后只访问一个字节,则拿到了a的第一个字节
}

int main()
{
 int ret=check_sys();
 if(ret==1)
  printf("小端字节序\n");
 else
  printf("大端字节序\n");
}




