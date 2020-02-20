#include <stdio.h>
int main()
{
    char assignment= ' ';
    char var[27]="";
    int value[26]={0};
    for(int i=0;i<26;i++)
        var[i] = i+65;
    while(1)
    {
        scanf("%c",&assignment);
        if(assignment == '!')
        {
            printf("!\n");
            break;
        }
        else if(assignment == '=')
        {
            char varribles = ' ';
            int num=0;
            scanf(" %c",&varribles);
            var[varribles-65] = varribles;
            scanf(" %d",&num);
            value[varribles-65] = num;
            if(num > 32767 || num < -32768)
            {
                value[varribles-65] =0;
            }
        }
        else if(assignment == '#')
        {
            char varribles = ' ';
            scanf(" %c",&varribles);
            printf("%d\n",value[varribles-65]);
        }
        else if(assignment == '+')
        {
            char varribles_1 = ' ';
            char varribles_2 = ' ';
            scanf(" %c",&varribles_1);
            scanf(" %c",&varribles_2);
            value[varribles_1-65] = value[varribles_1-65]+value[varribles_2-65];
        }
        else if(assignment == '-')
        {
            char varribles_1 = ' ';
            char varribles_2 = ' ';
            scanf(" %c",&varribles_1);
            scanf(" %c",&varribles_2);
            value[varribles_1-65] = value[varribles_1-65]-value[varribles_2-65];
        }
        else if(assignment == '*')
        {
            char varribles_1 = ' ';
            char varribles_2 = ' ';
            scanf(" %c",&varribles_1);
            scanf(" %c",&varribles_2);
            value[varribles_1-65] = value[varribles_1-65]*value[varribles_2-65];
        }
        else if(assignment == '/')
        {
            char varribles_1 = ' ';
            char varribles_2 = ' ';
            scanf(" %c",&varribles_1);
            scanf(" %c",&varribles_2);
            value[varribles_1-65] = value[varribles_1-65]/value[varribles_2-65];
        }
    }
    return 0;
}
