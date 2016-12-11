#include<stdio.h>
#include <string.h>
main()
{
    int n,k;
    scanf("%d",&n);
    int arr[n][6],i,j,swap,swap2,swap3;
    for(k=0; k<n; k++)
    {
        arr[k][0]=1;
        arr[k][1]=2;
        arr[k][2]=3;
        arr[k][3]=5;
        arr[k][4]=4;
        arr[k][5]=6;
    }
    char ch[n][1001];
    for(i=0; i<n; i++)
    {
        scanf("%s",ch[i]);
    }
    for(i=0; i<n; i++)
    {
        int length = strlen(ch[i]);
        for(j=0;j<length;j++)
        {
            swap=0;
            swap2=0;
            swap3=0;
            if(ch[i][j]=='F')
            {
                swap=arr[i][0];
                arr[i][0]=arr[i][3];
                swap2=arr[i][1];
                arr[i][1]=swap;
                arr[i][3]=arr[i][5];
                arr[i][5]=swap2;
            }
            if(ch[i][j]=='L')
            {
                swap=arr[i][0];
                arr[i][0]=arr[i][4];
                arr[i][4]=arr[i][5];
                arr[i][5]=arr[i][2];
                arr[i][2]=swap;
            }
            if(ch[i][j]=='R')
            {
                swap=arr[i][0];
                arr[i][0]=arr[i][2];
                arr[i][2]=arr[i][5];
                arr[i][5]=arr[i][4];
                arr[i][4]=swap;
            }
            if(ch[i][j]=='C')
            {
                swap=arr[i][1];
                arr[i][1]=arr[i][4];
                arr[i][4]=arr[i][3];
                arr[i][3]=arr[i][2];
                arr[i][2]=swap;
            }
            if(ch[i][j]=='D')
            {
                swap=arr[i][4];
                arr[i][4]=arr[i][1];
                arr[i][1]=arr[i][2];
                arr[i][2]=arr[i][3];
                arr[i][3]=swap;
            }
            if(ch[i][j]=='B')
            {
                swap=arr[i][0];
                arr[i][0]=arr[i][1];
                arr[i][1]=arr[i][5];
                arr[i][5]=arr[i][3];
                arr[i][3]=swap;
            }
        }
    }
    if(n==1)
        printf("%d",arr[0][1]);
    else
    {
        for(i=0; i<n; i++)
        {
            printf("%d ",arr[i][1]);
        }
    }

}
