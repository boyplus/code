//function แบบที่3
#include<stdio.h>
#include<string.h>
int main()
{
    char input[80];
    scanf("%s",input);
    int length = strlen(input),i,num[3] ={0,1,2},temp;
    for(i=0;i<length;i++)
    {
        if(input[i] =='A')
        {
            temp = num[1];
            num[1] = num[0];
            num[0] = temp;
        }
        else if(input[i] =='B')
        {
            temp = num[2];
            num[2] = num[1];
            num[1] = temp;
        }
        else if(input[i] =='C')
        {
            temp = num[2];
            num[2] = num[0];
            num[0] = temp;
        }
    }
    for(i=0;i<3;i++)
    {
        if(num[i] == 0)
            printf("%d\n",i+1);
    }
    return 0;
}
