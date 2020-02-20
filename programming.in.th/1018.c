#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    char string[n][3];
    int num[n];
    char position = 'E';
    int x=0,y=0;
    int dead =0;
    for(i=0;i<n;i++)
    {
        scanf("%s %d",&string[i],&num[i]);
        if(string[i][0] == 'F'&& dead ==0)
        {
            if(position == 'E')
            {
                x = x+num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
            else if(position == 'S')
            {
                y = y-num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
            else if(position == 'N')
            {
                y = y+num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
            else if(position == 'W')
            {
                x = x-num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
        }
        if(string[i][0] == 'R' && dead ==0)
        {
            if(position == 'E')
            {
                position = 'S';
                y = y-num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
            else if(position == 'N')
            {
                position = 'E';
                x = x+num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
            else if(position == 'S')
            {
                position = 'W';
                x = x-num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
            else if(position == 'W')
            {
                position = 'N';
                y = y+num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
        }
        if(string[i][0] == 'L' && dead ==0)
        {
            if(position == 'N')
            {
                position = 'W';
                x = x-num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
            else if(position == 'S')
            {
                position = 'E';
                x = x+num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
            else if(position == 'E')
            {
                position = 'N';
                y = y+num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
            else if(position == 'W')
            {
                position = 'S';
                y = y-num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
        }
        if(string[i][0] == 'B' && dead ==0)
        {
            if(position == 'N')
            {
                position = 'S';
                y = y-num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
            else if(position == 'S')
            {
                position = 'N';
                y = y+num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
            else if(position == 'E')
            {
                position = 'W';
                x = x-num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                   printf("DEAD\n");
                    return 0;
                }
           }
           else if(position == 'W')
           {
                position = 'E';
                x = x+num[i];
                if(x >= 50000 || x<=-50000 || y>=50000 || y<=-50000)
                {
                    printf("DEAD\n");
                    return 0;
                }
            }
        }
    }
    if(dead == 0)
    {
        printf("%d %d\n",x,y);
        printf("%c",position);
    }
    return 0;
}
