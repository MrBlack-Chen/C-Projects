#include<stdio.h>
/*
int main()
{
 char arr1[]="abcdef";
 char arr2[]="abcdef";
 if(arr1==arr2)//因为数组名为首元素的地址
//而arr1和arr2为两个不同的数组
//则在内存中申请两块不同的空间,则首元素地址不同，那么打印结果为haha
  printf("hehe\n");
 else
   printf("haha\n");
 const char* p1="abcdef";
 const char* p2="abcdef";
//并不是指将字符串"abcdef"赋给指针
//因为指针是用来存放地址的,实际上是将a的地址存到指针
//且此时"abcdef"为常量字符串,即不能被修改
//(那么最好用const修饰*p防止被修改)
//那么对于字符串"abcdef"而言
//既然不能被修改,则只要在内存中申请一块空间即可(可以节约内存)
//那么p1和p2指向的都是这块空间的'a',即p1=p2，那么打印结果为hehe
 if(p1==p2)
  printf("hehe\n");
 else
  printf("haha\n");
 return 0;
}
*/


int main()
{
 int arr[6]={1,2,3,4,5,6};
 int* p=arr;//将arr 数组首元素地址放到指针p
 int i=0;
 for(i=0;i<6;i++)
  {
  printf(" %d ",arr[i]);//通过下标引用符来打印
  printf(" %d ",*(p+i));//通过指针解引用来打印
  printf(" %d ",*(arr+i));
 //因为arr为首元素的地址,既然是地址
 //则也可以通过解引用来访问数组元素
//由此可看出指针p与arr是完全等效的
//则下方下标引用符的运用中可以将arr换成指针p
  printf(" %d ",p[i]);
  }
 return 0;
}