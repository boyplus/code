#include <stdio.h>
#include <math.h>
#include <string.h>
char string[50000]="";
int main()
{
    int i,j,k,n;
    int string_length=0;
    int count_num=0,count_position=0;
    int num_result=0;
    double position_x=0.00;
    double position_y=0.00;
    while(1)
    {
        scanf("%s",&string);
        string_length = strlen(string);
        for(i=0;i<string_length;i++)
        {
            if(string[i] >= 'A' && string[i] <= 'Z')
            {
                count_position++;
            }
            if(string[i] >='0' && string[i] <= '9')
            {
                count_num++;
            }
        }
        if(count_num==1)
        {
            num_result = string[0]-48;
        }
        else if(count_num==2)
        {
            num_result = ((string[0]-48)*10)+(string[1]-48);
        }
        else if(count_num == 3)
        {
            num_result = ((string[0]-48)*100)+((string[1]-48)*10)+(string[2]-48);
        }
        if(string[count_num] == 'N')
        {
            if(count_position==2)
            {
                if(string[count_num+1] == 'E')
                {
                    position_x+=(num_result/(sqrt(2.0000)));
                    position_y+=(num_result/(sqrt(2.0000)));
                }
                if(string[count_num+1] == 'W')
                {
                    position_x-=(num_result/(sqrt(2.0000)));
                    position_y+=(num_result/(sqrt(2.0000)));
                }
            }
            if(count_position==1)
            {
                position_y+=num_result;
            }
        }
        else if(string[count_num] == 'E')
        {
           position_x+=num_result;
        }
        else if(string[count_num] == 'S')
        {
            if(count_position==1)
            {
                position_y-=num_result;
            }
            if(count_position==2)
            {
                if(string[count_num+1] == 'W')
                {
                    position_x-=(num_result/(sqrt(2.0000)));
                    position_y-=(num_result/(sqrt(2.0000)));
                }
                if(string[count_num+1] == 'E')
                {
                    position_x+=(num_result/(sqrt(2.0000)));
                    position_y-=(num_result/(sqrt(2.0000)));
                }
            }
        }
        else if(string[count_num] == 'W')
        {
            position_x-=num_result;
        }
        count_num=0;
        count_position=0;
        num_result=0;
        if(string_length==1)
        {
            if(string[0] == '*')
            {
                getchar();
                printf("%.3lf %.3lf\n",position_x,position_y);
                double first = pow((0-position_x),2);
                double second = pow((0-position_y),2);
                double result = sqrt(first+second);
                printf("%.3lf\n",result);
                return 0;
            }
        }
    }
    return 0;
}
