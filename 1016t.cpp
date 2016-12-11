#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
main()
{
    char move[3];
    int i;
    double x=0,y=0,r;
    float d;
    for(i=0; i<=500; i++)
    {
        scanf("%f",&d);
        scanf("%s",move);
        if(strcmp("N",move)==0)y+=d;
        else if(strcmp("E",move)==0)x+=d;
        else if(strcmp("W",move)==0)x-=d;
        else if(strcmp("S",move)==0)y-=d;
        else if(strcmp("NE",move)==0)
        {
            x+=(d/sqrt(2));
            y+=(d/sqrt(2));
        }
        else if(strcmp("SE",move)==0)
        {
            x+=(d/sqrt(2));
            y-=(d/sqrt(2));
        }
        else if(strcmp("NW",move)==0)
        {
            x-=(d/sqrt(2));
            y+=(d/sqrt(2));
        }
        else if(strcmp("SW",move)==0)
        {
            x-=(d/sqrt(2));
            y-=(d/sqrt(2));
        }
        else if(strcmp("*",move)==0)break;
    }
    printf("%.3lf %.3lf\n%.3lf",x,y,sqrt(x*x+y*y));
    //system("pause");
}
