#include<conio.h>
#include<stdio.h>
#define MAX 50

/*
File bai3.txt chua du lieu gom cac tuyen duong va diem dau diem cuoi
Chuong trinh in ra 1 dong gom tuyen duong ket noi giua 2 dia diem
dong thoi in ra filebai3output.txt chua ket qua
*/

int Tuyenduong[MAX][MAX];
int Tuyenpho[MAX];
int dau,cuoi,n;
void BFS()
{
  int queue[MAX];
  int truoc = 1, sau = 1, u, v;
  queue[truoc] = dau;
  Tuyenpho[dau] = 1;
do
{
      u = queue[truoc];
      truoc++;
  if(u == cuoi)
    break;
  for (int v = 1; v <= n+2; v++)
    {
       if(Tuyenduong[u][v]==1 && Tuyenpho[v]==0)
      {
        sau ++;
        queue[sau] = v;
        Tuyenpho[v] = u;
      }
    }
  } while (truoc <= sau);
}

int main(int argc, char const *argv[])
{
  int m;
  FILE* fp;
  FILE* fp1;
  fp = fopen( "bai3.txt", "r" );
  fscanf( fp, "%d %d %d %d", &n, &m, &dau, &cuoi );
  int dau1 ,cuoi1 ;
  for(int j = 0; j <= n + 2; j++ )
  {
    fscanf( fp, "%d %d", &dau1, &cuoi1);
    Tuyenduong[dau1][cuoi1]= 1;
  }
  fclose(fp);
  BFS();
  fp1 = fopen( "bai3output.txt", "a+" );
    if ( Tuyenpho[cuoi] == 0 )
      {
       printf( "Khong tim thay duong !\n" );
       fprintf(fp1, "Khong tim thay duong !\n");
      }
    else
   {
       while(cuoi != dau)
      {
        printf( "%d - ", cuoi);
        fprintf(fp1, "%d - ", cuoi);
        cuoi= Tuyenpho[cuoi];
      }
  printf("%d", dau);
  fprintf(fp1, "%d", dau);
   }
   fclose(fp1);
return 0;
getch();
}
