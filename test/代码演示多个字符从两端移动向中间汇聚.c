//代码演示多个字符从两端移动向中间汇聚
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>            
int main()           
{
char arr1[]="no pain,no gain";
char arr2[]="###############";
int left=0;     int right=strlen(arr1)-1;
while(left<=right)
 {
  arr2[left]=arr1[left];  //利用此实现对arr2的重赋值
  arr2[right]=arr1[right];//以循环来形成移动假象
  left++;   right--;
  printf("%s\n",arr2);
  Sleep(1000);//是Windows提供给C语言的库函数,单位为毫秒ms,则1000ms=1s,要引头文件<windows.h>
  system("cls");
 }
return 0;
}            
