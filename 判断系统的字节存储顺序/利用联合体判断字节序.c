int check_sys()
{
  union Un//因为联合体的成员是共用同一块空间的,而c为char类型,则拿出c相当于拿出了a的第一个字节
   {            //判断第一个字节（值等同于c）为0还是1即可判断字节序
     char c;
     int a;
   }u;
   u.a=1; //a为0x 01 00 00 00
  return u.c;
}

int main()
{
 int ret=check_sys();
 if(ret==1)
  printf("小端字节序\n");
 else
  printf("大端字节序\n");
}




