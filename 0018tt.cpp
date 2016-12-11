#include<stdio.h>
int main()
{
    int N,at,i,j,k=0;
    scanf("%d %d",&N,&at);
//  if(at>= 2 && N<=1000 && at<N){
    int out[N],mem[1001];
    for(i=0; i<1001; i++)
        mem[i]=0;
    for(i=2; i<=N; i++)
    {

        for(j=i; j<=N; j+=i)
        {
            if(j!=mem[j])
            {
                mem[j]=j;
                out[k]=j;
                k++;
            }
        }

    }

    printf("%d",out[at-1]);//}
    return 0;
}
