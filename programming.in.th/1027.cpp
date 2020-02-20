#include <stdio.h>
#include <string.h>
char string[10001]="";
int main()
{
    int i,j,k,n,have_player=7;
    int score[7]={0};
    char name[8]={"ABCDEFG"};
    while(1)
    {
        int min=99999;
        scanf("%s",string);
        if(strcmp(string,"!")==0)
            break;
        int length = strlen(string);
        int count=0;
        for(i=0;i<length;i++)
            if(score[(string[i])-65]!=-1)
                score[(string[i])-65]++;
        for(i=0;i<7;i++)
            if(score[i] <= min && score[i]!=-1)
                min = score[i];
        for(i=0;i<7;i++)
            if(score[i] == min&&score[i]!=-1)
                count++;
        if(count==1)
        {
            for(i=0;i<7;i++)
            {
                if(score[i] == min&&score[i]!=-1 && have_player!=1)
                {
                    have_player--;
                    name[i] = '-';
                    score[i]=-1;
                }
            }
        }
    }
    int temp=0;
    char name_temp;
    for(i=0;i<7;i++)
    {
        for(j=i+1;j<7;j++)
        {
            if(score[i] < score[j] && score[i]!=-1 && score[j]!=-1)
            {
                temp = score[i];
                score[i] = score[j];
                score[j] = temp;
                name_temp = name[i];
                name[i] = name[j];
                name[j] = name_temp;
            }
            if(score[i] == score[j] && score[i]!=-1&&score[j]!=-1)
            {
                if(name[i] > name[j])
                {
                    name_temp = name[i];
                    name[i] = name[j];
                    name[j] = name_temp;
                }
            }
        }
    }
    printf("%d\n",have_player);
    for(i=0;i<7;i++)
        if(name[i]!='-')
            printf("%c %d\n",name[i],score[i]);
    return 0;
}
