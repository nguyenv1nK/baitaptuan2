#include <stdio.h>
#include <conio.h>
#include <string.h>

 //Chuong trinh kiem tra va sua loi cua day ngoac trong file bai1.txt roi in ket qua vao file bai1output.txt


int main ()
 {
	int n = 0, i = 0, s = 0, sai, n1 = 0, n2 = 0, j, j1, j2 ;
FILE *fp;
   char a[200];
   fp = fopen("bai1.txt", "r");
    fscanf(fp, "%s", a);
   	fclose(fp);
   FILE *fp1;
 fp1 = fopen("bai1output.txt", "w+");
   for(i = 0; i < strlen(a); i++)

    {
     if(a[i] == '(')
           n++;
     if(a[i] == ')'&&n == 0)
            {
            s++;
            fprintf(fp1, "\n(%d ", i-1);
            }
        if(a[i] == ')' && n!=0)
            {
             n--;
             }
    if(a[i] == '[')
           n1++;
     if(a[i] == ']'&& n1 == 0)
            {
            s++;
            fprintf(fp1, "\n[%d ", i-1);
            }
        if(a[i] ==']'&& n1!=0)
            {
             n1--;
             }
    if(a[i] =='{')
           n2++;
     if(a[i] =='}' && n2==0)
            {
            s++;
            fprintf(fp1, "\n{%d ", i-1);
            }
        if(a[i] == '}'&& n2!=0)
            {
             n2--;
            }

    }
    for( j = 1; j <= n; j++)
    {
        fprintf(fp1, "\n)%d", strlen(a)+j);
    }
    for( j1 = 1; j1 <= n1; j1++)
    {
        fprintf(fp1, "\n]%d", strlen(a)+n+j1);
    }
    for( j2 = 1; j<=n2; j2++)
    {
        fprintf(fp1, "\n}%d", strlen(a)+n+n1+j2);
    }
 sai = s + n + n1 + n2;

 fprintf(fp1, "\nSo loi sai cua a la %d ", sai);
 fclose(fp1);
 printf("\nDone!\nMo file bai1output.txt de xem ket qua!");
	getch();
  	return 0;
}
