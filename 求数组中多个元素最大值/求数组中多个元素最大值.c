//求数组中多个数的最大值      
#include<stdio.h>  
int main()            
{
int arr[]={-1,-3,-4,-6,2,1,9};
int max=arr[0];   //不能简单的赋为0
                          //因为假如全为负数的话,0就会为最大,则输出为0,
                         //要赋为数组中的某个数,假设它为最大
int i=0; 
int sz=sizeof(arr)/sizeof(arr[0]);
for(i=1;i<sz;i++)
  {
   if(max<arr[i])
   max=arr[i];
  }
printf("max=%d\n",max);
return 0;
}            
