#include <stdio.h>
#include <string.h>
int main()
{
    int page;
    scanf("%d",&page);
    int i=0,v=0,x=0,l=0,c=0;
    int c1;
    int temp =0;
    for(c1=1;c1<=page;c1++)
    {
        temp = c1;
        if(temp >= 100)
        {
            c = c+(temp/100);
            temp = temp-((temp/100)*100);
        }
        if(temp >=90)
        {
            c = c+1;
            x = x+1;
            temp = temp-90;
        }
        if(temp >=50)
        {
            l = l+1;
            temp = temp-50;
        }
        if(temp >=40)
        {
            l = l+1;
            x = x+1;
            temp = temp-40;
        }
        if(temp >= 10)
        {
            x = x+(temp/10);
            temp = temp-((temp/10)*10);
        }
        if(temp >=9)
        {
            x = x+1;
            i = i+1;
            temp = temp - 9;
        }
        if(temp >=5)
        {
            v = v+1;
            temp = temp-5;
        }
        if(temp >=4)
        {
            v = v+1;
            i = i+1;
            temp = temp-4;
        }
        if(temp >=1)
        {
            i = i+temp;
        }
    }
    printf("%d %d %d %d %d",i,v,x,l,c);
    return 0;
}