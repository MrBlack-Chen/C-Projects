//利用递归解决汉若塔问题   
#include<stdio.h>
int cnt=0;  //cnt要定义为全局变量(不会消亡)         
int Move(int n,char A,char B,char C) 
{
  if(n==1)
  {
  printf("%c-->%c\n",A,C);
  cnt++;//若将cnt定义为局部变量,当此执行完了之后,生命周期结束,自动消亡
  }     //就不能够实现每打印一次,计数一次(因为会被初始化)
  else   
  {
  Move(n-1,A,C,B);//将n个盘子从A-->C的流程（先大事化小(问题简单化思考),再把问题不断拆分）
                  //1.将(n-1)个盘子从A-->B(与将n个盘子从A-->C同理,即将n-1赋给n,将B赋给C)
                  //2.将第n个盘子从A-->C
                  //3.将(n-1)个盘子从B-->C(与将n个盘子从A-->C同理,即将n-1赋给n,将B赋给A）
  printf("%c-->%c\n",A,C);
  cnt++;
  Move(n-1,B,A,C);
  }
 return cnt;
}            
int main()                       
{
int n=1;
printf("请输入盘子数 n=");
scanf("%d",&n);
int ret=Move(n,'A','B','C');
printf("移动次数为：%d\n",ret);
 return 0;
}
