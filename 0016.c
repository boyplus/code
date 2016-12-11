#include<stdio.h>
int main()
{
    int a,i,j;
    scanf("%d",&a);
    char input[a+1];
    scanf("%s",&input);
    char ari[3]={'A','B','C'};
    char budo[4]={'B','A','B','C'};
    char robin[6]={'C','C','A','A','B','B'};
    char name[3][20] = {"Adrian","Bruno","Goran"};
    int score1[3]={0};
    for(i=0;i<a+1;i++)
    {
        if(i %3 ==0)
        {
            if(input[i] == ari[i%3])
            {
                score1[0]++;
            }
        }
        else if(i%3 == 1)
        {
            if(input[i] == ari[i%3])
            {
                score1[0]++;
            }
        }
        else if(i%3 == 2)
        {
            if(input[i] == ari[i%3])
            {
                score1[0]++;
            }
        }
    }
    for(i=0;i<a+1;i++)
    {
        if(i%4 == 0)
        {
            if(input[i] == budo[i%4])
            {
                score1[1]++;
            }
        }
        else if(i%4 == 1)
        {
            if(input[i] == budo[i%4])
            {
                score1[1]++;
            }
        }
        else if(i%4 == 2)
        {
            if(input[i] == budo[i%4])
            {
                score1[1]++;
            }
        }
        else if(i%4 == 3)
        {
            if(input[i] == budo[i%4])
            {
                score1[1]++;
            }
        }
    }
    for(i=0;i<a+1;i++)
    {
        if(i%6 == 0)
        {
            if(input[i] == robin[i%6])
            {
                score1[2]++;
            }
        }
        else if(i%6 == 1)
        {
            if(input[i] == robin[i%6])
            {
                score1[2]++;
            }
        }
        else if(i%6 == 2)
        {
            if(input[i] == robin[i%6])
            {
                score1[2]++;
            }
        }
        else if(i%6 == 3)
        {
            if(input[i] == robin[i%6])
            {
                score1[2]++;
            }
        }
        else if(i%6  == 4)
        {
            if(input[i] == robin[i%6])
            {
                score1[2]++;
            }
        }
        else if(i%6 == 5)
        {
            if(input[i] == robin[i%6])
            {
                score1[2]++;
            }
        }
    }
    int max = score1[0];
    for(i=0;i<3;i++)
    {
        if(score1[i] >=max)
        {
            max = score1[i];
        }
    }
    printf("%d\n",max);
    for(i=0;i<3;i++)
    {
        if(score1[i] == max)
        {
            printf("%s\n",name[i]);
        }
    }
    return 0;
}
