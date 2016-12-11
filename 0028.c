#include <stdio.h>
#include <math.h>
#include <string.h>
int main()
{
    char name_team[4][21];
    int i,j,k,n;
    int score[4][4]={0};
    for(i=0;i<4;i++)
    {
        scanf("%s",&name_team[i]);
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&score[i][j]);
        }
    }
    int score_team1=0;
    int score_team2 =0;
    int score_team3=0;
    int score_team4=0;
    if(score[0][1] > score[1][0])
    {
        score_team1 = score_team1+3;
    }
    if(score[0][2] > score[2][0])
    {
        score_team1 = score_team1+3;
    }
    if(score[0][3] > score[3][0])
    {
        score_team1+=3;
    }
    if(score[0][1] == score[1][0])
    {
        score_team1+=1;
    }
    if(score[0][2] == score[2][0])
    {
        score_team1+=1;
    }
    if(score[0][3] == score[3][0])
    {
        score_team1+=1;
    }
    if(score[1][0] > score[0][1])
    {
        score_team2 += 3;
    }
    if(score[1][2] > score[2][1])
    {
        score_team2+=3;
    }
    if(score[1][3] > score[3][1])
    {
        score_team2+=3;
    }
    if(score[1][0] == score[0][1])
    {
        score_team2+=1;
    }
    if(score[1][2] == score[2][1])
    {
        score_team2+=1;
    }
    if(score[1][3] == score[3][1])
    {
        score_team2+=1;
    }
    if(score[2][0] > score[0][2])
    {
        score_team3+=3;
    }
    if(score[2][1] > score[1][2])
    {
        score_team3+=3;
    }
    if(score[2][3] > score[3][2])
    {
        score_team3+=3;
    }
    if(score[2][0] == score[0][2])
    {
        score_team3+=1;
    }
    if(score[2][1] == score[1][2])
    {
        score_team3+=1;
    }
    if(score[2][3] == score[3][2])
    {
        score_team3+=1;
    }
    if(score[3][0] > score[0][3])
    {
        score_team4+=3;
    }
    if(score[3][1] > score[1][3])
    {
        score_team4+=3;
    }
    if(score[3][2] > score[2][3])
    {
        score_team4+=3;
    }
    if(score[3][0] == score[0][3])
    {
        score_team4+=1;
    }
    if(score[3][1] == score[1][3])
    {
        score_team4+=1;
    }
    if(score[3][2] == score[2][3])
    {
        score_team4+=1;
    }
    int score_2[4] = {score_team1,score_team2,score_team3,score_team4};
    int score_last[4] = {score_team1,score_team2,score_team3,score_team4};
    char temp_string[4][21];
    char temp_string_2[21];
    for(i=0;i<4;i++)
    {
        strcpy(temp_string[i],name_team[i]);
    }
    int temp=0;
    int goal_1[4]={0};
    int goal_2[4]={0};
    int temp_2=0;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            goal_1[i] = goal_1[i]+score[i][j];
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            goal_2[i] = goal_2[i]+score[j][i];
        }
    }
    int result[4];
    for(i=0;i<4;i++)
    {
        result[i] = goal_1[i]-goal_2[i];
    }
    for(i=0;i<4;i++)
    {
        for(j=i+1;j<4;j++)
        {
            if(score_last[i] < score_last[j])
            {
                temp = score_last[i];
                score_last[i] = score_last[j];
                score_last[j] = temp;
                strcpy(temp_string_2,temp_string[i]);
                strcpy(temp_string[i],temp_string[j]);
                strcpy(temp_string[j],temp_string_2);
            }
            else if(score_last[i] == score_last[j])
            {
                    if(result[i] < result[j])
                    {
                        temp = score_last[i];
                        score_last[i] = score_last[j];
                        score_last[j] = temp;
                        strcpy(temp_string_2,temp_string[i]);
                        strcpy(temp_string[i],temp_string[j]);
                        strcpy(temp_string[j],temp_string_2);
                    }
                    else if(result[i] == result[j])
                    {
                        if(goal_1[i] < goal_2[j])
                        {
                             temp = score_last[i];
                            score_last[i] = score_last[j];
                            score_last[j] = temp;
                            strcpy(temp_string_2,temp_string[i]);
                            strcpy(temp_string[i],temp_string[j]);
                            strcpy(temp_string[j],temp_string_2);
                        }
                    }
            }
        }
    }
    for(i=0;i<4;i++)
    {
        printf("%s %d\n",temp_string[i],score_last[i]);
    }
    return 0;
}
