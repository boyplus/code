#include<stdio.h>
#include<string.h>

int main()
{
char a[101],b[101],op;
int sa,sb,i;
scanf("%s",&a);
fflush(stdin);
scanf("%c",&op);
fflush(stdin);
scanf("%s",&b);
sa=strlen(a);
sb=strlen(b);
if(op=='*')
{
printf("1");
for(i=0;i<sa+sb-2;i++)
printf("0");
}
else if(op=='+')

if(sa>sb)
{
a[sa-sb]='1';
printf("%s",a);
}
else if(sb>sa)
{
b[sb-sa]='1';
printf("%s",b);
}

else
{
printf("2");
for(i=0;i<sa-1;i++)
printf("0");
}}
