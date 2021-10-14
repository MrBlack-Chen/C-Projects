//创建扫雷游戏(及优化)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define Easy 20
#define Middle 50

//创建初始化数组的函数(要用此初始化两个不同数组)
void initboard(char board[ROWS][COLS],int rows,int cols,char set)
{
 int i=0;  int j=0;
 for(i=0;i<rows;i++)
 { 
   for(j=0;j<cols;j++)
    {
     board[i][j]=set;
    }
 }
}

//创建设置雷的函数    
void setboard(char board[ROWS][COLS],int row,int col)
{ //将雷设置在9*9的棋盘中,但上面为了保持一致(因为传过来的是ran数组11*11的),则仍写成ROWS
  //可以在后面代码的实现中灵活处理应对
int x=0;  int y=0;  int cnt=0;
 while(cnt<Easy)
  { //雷是设置在9*9的棋盘中,则在11*11的棋盘中将雷布置在下标1~9的区域中
    //则将随机数%模上row/col(余数为0～8)再+1
   x=rand()% row +1;  y=rand()% col +1;
   if(board[x][y]=='0')
    {    //用字符0代表没雷，用字符1代表雷
      board[x][y]='1';
      cnt++;
    }
   }
}

//创建打印棋盘的函数
void printboard(char board[ROWS][COLS],int row,int col)
{
  int i=0;  int j=0;
  printf("标");
  for(i=1;i<=row;i++)//打印列号要在打印行之前
  {               
    printf("%d ",i);
  }       
  printf("\n");
  for(i=1;i<=row;i++)
  {
    printf("%d ",i);//打印行号
    for(j=1;j<=col;j++)
    {
     printf("%c ",board[i][j]);//数组里的元素对应的就是一个字符
    }  
   printf("\n");
  }
}

int getran(char board[ROWS][COLS],int x,int y)
{
  return board[x-1][y-1]+board[x][y-1]
   +board[x+1][y-1]+board[x-1][y]+board[x+1][y]
   +board[x-1][y+1]+board[x][y+1]+board[x+1][y+1]
    -8*'0';
}//字符+-字符变成数字,因为实际操作的为ASCII码值

//创建优化函数(点击以后可以展开一片信息)
void develop(char ran[ROWS][COLS],char show[ROWS][COLS],int x,int y)
{
  if(x>=1&&x<=ROW&&y>=1&&y<=COL)
 {
  if(ran[x][y]=='0')
   {
     if(ran[x-1][y-1]=='0'&&show[x-1][y-1]=='*')
     {
      int cnt=getran(ran,x-1,y-1);
       if(cnt==0)
      {
      show[x-1][y-1]=' ';
      }
       if(cnt!=0)
      {
       show[x-1][y-1]=cnt+'0';
      }
      develop(ran,show,x-1,y-1);    
     }
     if(ran[x-1][y]=='0'&&show[x-1][y]=='*')
     {
      int cnt=getran(ran,x-1,y);
       if(cnt==0)
       {
        show[x-1][y]=' ';
       }
       if(cnt!=0)
       {
        show[x-1][y]=cnt+'0';
       }
      develop(ran,show,x-1,y);    
     }
     if(ran[x-1][y+1]=='0'&&show[x-1][y+1]=='*')
     {
      int cnt=getran(ran,x-1,y+1);
       if(cnt==0)
       {
        show[x-1][y+1]=' ';
       }
       if(cnt!=0)
       {
        show[x-1][y+1]=cnt+'0';
       }
      develop(ran,show,x-1,y+1);
     }
   }
 }
}

//创建判断扫雷成功的函数
char Iswin(char show[ROWS][COLS],int row,int col)
{
  int i=0;  int j=0; int cnt=0;
  for(i=1;i<=row;i++)
  {
    for(j=1;j<=col;j++)
     {
      if(show[i][j]=='*')
      cnt++;
     }
  }
   if(cnt>Easy)//通过计算剩下的'*'有多少
   {           //与Easy(20个雷都没有显示,为'*')比较
     return 'C';//若cnt>20,则说明还有不是雷的,则返回'C',游戏继续
   } //
   if(cnt==Easy)//若cnt=20,则说明剩下没点的都是雷,则扫雷成功
   { 
    return 'W';
   }
}

//创建扫雷主体函数
void findran(char ran[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
 int x=0;  int y=0;  int win=0;
 char ret=0;
 while(win<row*col-Easy)
  {
   printf("请输入坐标：>");
   scanf("%d%d",&x,&y);
   if(x>=1&&x<=row && y>=1&&y<=col)
    {
     if(ran[x][y]=='1')
     {
      printf("很遗憾，你被雷炸死\n");
      printboard(ran,ROW,COL);
      break;    
     }
     else    
     {  //不是雷,则要显示信息(则getran（）计算周围有多少雷)
      int cnt=getran(ran,x,y);
      show[x][y]=cnt+'0';//将cnt+'0'变成字符(因为show数组为字符数组)
      develop(ran,show,x,y);
      printboard(show,ROW,COL);
      ret=Iswin(show,ROW,COL);
      if(ret!='C')
      {
        break;
      }
     }
    }
  else
   {
    printf("坐标非法，请重新输入\n");
   }
  }
 if(ret=='W')
  {
    printf("恭喜你，扫雷成功\n");
  }
}

//创建游戏主体函数
void game()
{
 char ran[ROWS][COLS]={0};//存储雷的信息
 char show[ROWS][COLS]={0};//存储排雷信息
 initboard(ran,ROWS,COLS,'0');
 initboard(show,ROWS,COLS,'*');
 setboard(ran,ROW,COL);
 printboard(show,ROW,COL);
 findran(ran,show,ROW,COL);
}  //当两个都要用同一个函数初始化时且初始化内容不同时,可以将预期的初始化内容作为实参传过去
   //将初始化内容用对应的形参接收即可

void menu()//创建菜单函数
{
 printf("***********扫雷************\n");
 printf("**1.开始游戏   0.退出游戏**\n");
 printf("***************************\n");
}   
                     
int main()            
{
 int input=0;
 srand((unsigned int)time(NULL));
 do
 {
  menu();
  printf("请选择：>");
  scanf("%d",&input);
  switch(input)
   {
    case 1:
     game();
     break;
    case 0:
     printf("退出游戏\n");
      break;
    default:
     printf("选择错误,请重新选择\n");
      break;
   }
  }
  while(input);
return 0; 
}            



            
            
            
                                                
                                                    
