#include <stdio.h>
#include <string.h>
int dice[6] = {1,2,3,5,4,6};
void reset();
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    char string[1001];
    for(i=0;i<n;i++)
    {
        scanf("%s",string);
        int length = strlen(string);
        for(j=0;j<length;j++)
        {
            if(string[j] == 'F')
            {
                int temp = dice[3];
                dice[3] = dice[5];
                dice[5] = dice[1];
                dice[1] = dice[0];
                dice[0] = temp;
            }
            else if(string[j] == 'B')
            {
                int temp = dice[1];
                dice[1] = dice[5];
                dice[5] = dice[3];
                dice[3] = dice[0];
                dice[0] = temp;
            }
            else if(string[j] == 'L')
            {
                int temp = dice[2];
                dice[2] = dice[0];
                dice[0] = dice[4];
                dice[4] = dice[5];
                dice[5] = temp;
            }
            else if(string[j] == 'R')
            {
                int temp = dice[4];
                dice[4] = dice[0];
                dice[0] = dice[2];
                dice[2] = dice[5];
                dice[5] = temp;
            }
            else if(string[j] == 'C')
            {
                int temp = dice[1];
                dice[1] = dice[4];
                dice[4] = dice[3];
                dice[3] = dice[2];
                dice[2] = temp;
            }
            else if(string[j] == 'D')
            {
                int temp = dice[1];
                dice[1] = dice[2];
                dice[2] = dice[3];
                dice[3] = dice[4];
                dice[4] = temp;
            }
        }
        printf("%d ",dice[1]);
        reset();
    }
    return 0;
}
void reset()
{
    dice[0] = 1;
    dice[1] = 2;
    dice[2] = 3;
    dice[3] = 5;
    dice[4] = 4;
    dice[5] = 6;
}
