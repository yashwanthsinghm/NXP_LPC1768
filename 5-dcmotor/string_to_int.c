#include<stdio.h>
char s[]="1";
int num[10] ;
int x=0;
int y;
int main()
{ int i;
    printf("%s",s);
    for(i=0;s[i]!='\0';i++)
    {
        printf("%d",(s[i]-48));
        num[i]=(s[i]-48);
        x++;
    }
    printf("\n");
    for(i=0;i<x;i++)
    {
        printf("%d",num[i]);
    }
    y=(num[0]*10000)+(num[1]*1000)+(num[2]*100)+(num[3]*10)+(num[4]);
    printf("%d",y);

}
