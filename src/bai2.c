#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
/*
Chuong trinh tim kiem va thay the ki tu trong file bai2.txt
Lich su tim va sua se duoc luu vao file bai2output.txt
Ket qua chinh sua se duoc luu vao file bai2rp.txt 
*/
FILE *kiemtrafile(char *tenfile)
{
    int i,vol;
    tenfile="bai2.txt";
    FILE *p = fopen(tenfile,"a+");
    if(p != NULL)
    {
        char x[MAX];
        int co = 1;
        while(feof(p) != NULL)
        {
                fgets(x,MAX,p);
                for(i = 0;i<strlen(x);i++)
                {
                    vol =x[i];
                    if(vol < 33 || vol == 127)
                    {
                        co = 1;
                        break;
                    }
                }
        }
        if(co == 2)
            printf("Error:File contains special characters\n");
        else return p;
    }
}

void thaythe(char *str, const char *tucu, const char *tumoi)
{
     char *p, tam[MAX];
    int i = 0;
    int len;
    len = strlen(tucu);
    while ((p = strstr(str, tucu)) != NULL)
    {
        strcpy(tam, str);
        i = p - str;
        str[i] = '\0';
        strcat(str, tumoi);
        strcat(str, tam + i + len);
    }
}

int solanxuathien(char *tenfile,char tukhoa[],char tuthaythe[],int chucnang)
{
    char x[MAX],tenfout[100]= "bai2ouptput.txt";
    int i= 0,z= 0;
    int k, co, b, x1, x2, demdong;
    demdong = 0;
    FILE *p = kiemtrafile(tenfile);
    FILE *pTam;
    FILE *fout;
    fout = fopen(tenfout,"a+");
    fputs(tenfile,fout);
    fputs(" \n ",fout);
    if(chucnang == 1)
    {
        fputs("Chose 1\n",fout);
        fputs("\nKeyword : ",fout);
        fputs(tukhoa,fout);
        fputs(" \n ",fout);
    }
    else {
        fputs("Chose 2\n New keyword: ",fout);
        fputs(tuthaythe,fout);
        fputs("\nKeyword: ",fout);
        fputs(tukhoa,fout);
        fputs(" \n ",fout);
    }
    printf("Keyword : %s\n",tukhoa);
    pTam = fopen("bai2rp.txt","a+");

    int demlanxuathien;
    demlanxuathien = 0;
    while( feof(p) == 0 )
    {
            fgets( x, MAX, p);

            demdong++;
            for(i = 0; i < strlen(x);i++)
            {
                x2 = tukhoa[0];
                x1 = x[i];
                if(x1==x2||abs(x1-x2)==32)
                {
                    z = i+1;
                    b = 1;
                    while(b < strlen(tukhoa))
                    {
                        x1 = x[z];
                        x2 = tukhoa[b];
                        if(x1==x2||abs(x1-x2)==32)
                        {
                            b++;
                            z++;
                            co = 1;
                        }
                        else
                        {
                        co = 0;
                        break;
                        }
                    }
                    if(co == 1)
                    {
                        demlanxuathien++;
                        printf("Ln %d Col %d \n", demdong,i);
                        fputs("Ln ",fout);
                        fprintf(fout,"%d",demdong);
                        fputs(" Col ",fout);
                        fprintf(fout,"%d",i);
                        fputs(" \n ",fout);
                    }
                }
            }
            if(chucnang == 2)
            {

                thaythe(x,tukhoa,tuthaythe);
                fputs(x,pTam);
            }
    }
    fclose(p);
    fputs("\n",pTam);
    fclose(pTam);
    if(chucnang==1)
        {
    printf("Total appeared time: %d \n",demlanxuathien);
    fputs("Total appeared time: ",fout);
    fprintf(fout,"%d\n\n",demlanxuathien);
    fputs("\n",fout);
        }
    fclose(fout);
    return 0;
}
void timkiem(char *tenfile,int chucnang)
{
    char tukhoa[20];
    printf("Enter the keyword\n");
    fflush(stdin);
    gets(tukhoa);
    char tuthaythe[20];
    if(chucnang == 2)
    {
        printf("New keyword: \n");
        fflush(stdin);
        gets(tuthaythe);
    }
    solanxuathien(tenfile,tukhoa,tuthaythe,chucnang);
}
void main()
{
    fflush(stdin);
       int chucnang;
    do
    {
    printf("\n--------MENU----------\n");
    printf("Chose:\n");
    printf("1: Search\n");
    printf("2: Replace\n");
    printf("3 Exit\n");
    printf("Plese enter your chose:\n");
    printf("\n---------------------\n");
    scanf("%d",&chucnang);
    switch(chucnang)
    {
        case 1:
        case 2:timkiem("bai2.txt",chucnang) ;break;
        case 3: break;
    }
    }while(chucnang != 3);
    getch();
}
