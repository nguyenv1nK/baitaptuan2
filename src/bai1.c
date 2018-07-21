#include <stdio.h>
#include <conio.h>
#include <string.h>

 //Chuong trinh kiem tra va sua loi cua day ngoac trong file bai1.txt roi in ket qua vao file bai1output.txt


int main ()
 {
	int s = 0, n = 0, n1 = 0, n2 = 0;
	int sai;
FILE *fp;
FILE *fp1;
char a[200];
   	fp = fopen("bai1.txt", "r");
    fscanf(fp, "%s", a);
   	fclose(fp); 
//Kiem tra ki tu file 
for (int i = 0; i <strlen(a); ++i)
	{	if (a[0]==EOF)
			printf("File trong!\n");
			else if(a[i]!='('||a[i]!=')'||a[i]!='['||a[i]!=']'||a[i]!='{'||a[i]!='}')
				printf("Chuong trinh chua ki tu khong hop le, yeu cau kiem tra lai!\n");
		exit(0);
	}
fp1 = fopen("bai1output.txt", "w+");

//Kiem tra loi sai tai vi tri dau tien
if(a[0]==')')
	{
		s++;
     	fprintf(fp1, "\n( 0 ",);
    }
if(a[0]==']')
	{
		s++;
     	fprintf(fp1, "\n[ 0 ",);
    }
if(a[0]=='}')
	{
		s++;
     	fprintf(fp1, "\n{ 0 ",);
    }
//Kiem tra loi sai tai cac vi tri tiep theo
 //Kiem tra ngoac tron
for( i = 1; i < strlen(a); i++)
{
    if(a[i] == '(')
           n++;
    	else if(a[i] == ')')
        {	
         	if (n==0)
         	{	s++;
         		fprintf(fp1, "\n(%d ", i-1);
         	}
        	else 
            	{
            	 n--;
             	}
        }
  //Kiem tra ngoac vuong
	if(a[i] == '[')
           n1++;
   	else if(a[i] == ']')
        {
          	if (n1==0)
            {	
            	s++;
            	fprintf(fp1, "\n[%d ", i-1);
            }
       		else 
       		 	{
       		 		n1--;
       		 	}
       	}

  //Kiem tra ngoac nhon
	if(a[i] =='{')
           n2++;
    else if(a[i] =='}' && n2==0)
        {  if(n2==0)
           	{
            s++;
            fprintf(fp1, "\n{%d ", i-1);
            }
        	else
            {
             n2--;
	        }
	    }

}
    
//In ket qua vao file
for(int j = 1; j <= n; j++)
    {
        fprintf(fp1, "\n)%d", strlen(a)+j);
    }

for( j = 1; j <= n1; j++)
    {
        fprintf(fp1, "\n]%d", strlen(a)+n+j1);
    }

for( j = 1; j<=n2; j++)
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
