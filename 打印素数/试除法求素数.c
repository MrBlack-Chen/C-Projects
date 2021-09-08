//利用试除法求素数(100~200之间)
#include<stdio.h>
#include<math.h>           
int main()   
{
int i=0; int cnt=0;
for(i=100;i<=200;i++)
 {
  int j=0;
  for(j=2;j<=sqrt(i);j++)  //利用开平方因子之间的关系（有一个因子必定对应另一个）
   {                                   //则只要试除2~n½即可,则由此缩小试除范围,提高效率
   if(i%j==0)
   break;
   }
  if(j>sqrt(i))
   {  
    cnt++;
    printf("%d ",i);
   }
 }
printf("\ncnt=%d\n",cnt);
return 0;
}
        
            
            
            
            
            
                     
                                    
            
                       
            
                        
                               