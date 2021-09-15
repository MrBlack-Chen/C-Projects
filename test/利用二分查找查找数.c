//利用二分查找算法查找有序数组中的数(可以简化查找步骤,提高效率)   
#include<stdio.h>
int main()
{
int arr[11]={1,2,3,4,5,6,7,8,9,10,11,12};
int sz=sizeof(arr)/sizeof(arr[0]);
int left=0; int right=sz-1; int k=0;
printf("请输入查找数:");
scanf("%d",&k);
while(left<=right)
{
int mid=(left+right)/2;//mid的计算要放在循环里头,因为每一次循环之后left,right的值会变化
  if(k>arr[mid])
   {
    left=mid+1;
   }
  else if(k<arr[mid])
   { 
    right=mid-1;
   }
   else
    {
     printf("找到了,下标为：%d\n",mid);
     break;
    }
}    
if(left>right)
{
printf("找不到,请重新确认查找数是否输入正确");
}    
return 0;
}            
