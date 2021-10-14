//自创建三子棋游戏
#include<stdio.h>
#define ROW 3 //#define定义的标识符常量
#define COL 3 //本质就为常量
#include<stdlib.h>
#include<time.h>

void menu()//创建菜单函数
{
 printf("**********三子棋***********\n");
 printf("**1.开始游戏   0.退出游戏**\n");
 printf("***************************\n");
}
//创建数组初始化函数
void Initboard(char board[ROW][COL],int row,int col)
{
  int i=0;
  for(i=0;i<row;i++)
   {
     int j=0;
     for(j=0;j<col;j++)
      {
       board[i][j]=' ';
      }
   }
}

//创建打印棋盘的函数
void printboard(char board[ROW][COL],int row,int col)
{
 int i=0;
 for(i=0;i<row;i++)
 {
   int j=0;
   for(j=0;j<col;j++)//打印一行数据
   {               
    printf(" %c ",board[i][j]);
    if(j<col-1)
     printf("|");
   }
   printf("\n");
   if(i<row-1)//打印分割行
   {
    for(j=0;j<col;j++)
    {
     printf("---");
     if(j<col-1)
      printf("|");
     }
    }
   printf("\n");
 }
}

//创建玩家下棋的函数
void player_move(char board[ROW][COL],int row,int col)
{
  int x=0; int y=0;
  printf("玩家下\n");
  while(1)
  {
   printf("请输入坐标：>");
   scanf("%d%d",&x,&y);
  if(x>=1&&x<=3&&y>=1&&y<=3)
    {
     if(board[x-1][y-1]==' ')
     {
      board[x-1][y-1]='*';
      break;
     }
    else
      printf("\n该处已被落子，请重新输入\n");
    }
  else
    printf("\n输入非法，请重新输入\n");
  }   
}

//创建电脑自动下棋的函数
void computer_move(char board[ROW][COL],int row,int col)
{
 int x=0;   int y=0;
 printf("电脑下：>\n");
 while(1)
  {
   x=rand()% row;  y=rand()% col;
   if(board[x][y]==' ')
    {
      board[x][y]='#';
      break;
    }
  }
}

//创建判断平局的函数
int Isfull(char board[ROW][COL],int row,int col)
{
 int i=0;
 for(i=0;i<row;i++)
  {
    int j=0;
    for(j=0;j<col;j++)
    {
     if(board[i][j]==' ')
     {    
      return 0;
     }
    }
  }
  return 1;
}

//创建判断输赢的函数
char Iswin(char board[ROW][COL],int row,int col)
{
int i=0;
 for(i=0;i<row;i++)
 {  //判断横三行的赢
  if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][1]!=' ')
   {
    return board[i][1];
   }
 }
    //判断竖三列的赢
 for(i=0;i<col;i++)
 {
   if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[1][i]!=' ')
    {
    return board[1][i];
    }
 }
    //判断两个对角线的赢
 if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[1][1]!=' ')
  return board[0][0];
 if(board[2][0]==board[1][1]&&board[1][1]==board[0][2]&&board[1][1]!=' ')
   return board[2][0]; 
    //判断平局
 if(Isfull(board,ROW,COL)==1)
   return 'Q';
   //继续下
 return 'C';
}

void game()//创建游戏主体函数        
{   
  char board[ROW][COL]={0};
  char ret=0;//不能将Iswin直接赋在这
            //因为还没开始下,根本就没有数据
  Initboard(board,ROW,COL);
  printboard(board,ROW,COL);
  while(1)
  {
  player_move(board,ROW,COL);
  printboard(board,ROW,COL);
  ret=Iswin(board,ROW,COL);//引用的是
   if(ret!='C')         //下过子后的棋盘
   {
    break;
   }
  computer_move(board,ROW,COL);
  printboard(board,ROW,COL);
  ret=Iswin(board,ROW,COL);
   if(ret!='C')
    {
     break;
    }
   }
 if(ret=='*')//是判断相等,不是=赋值
  printf("玩家 Win\n");
 else if(ret=='#')
  printf("电脑 Win\n");
 else
  printf("平局\n");
}       
                 
int main()            
{
int input=0;
srand((unsigned int)time(NULL));
 do      //只要设置一次随机数生成起点即可
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



            
            
            
                                                
                                                    