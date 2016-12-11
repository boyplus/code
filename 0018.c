#include <stdio.h>
int kha[1200]={0};
int main()
{
	int i,j,k,n,p=0;
	scanf("%d %d",&n,&k);
	int num[n-1];
	int start = 2;
	int index=0;
	for(i=0;i<n-1;i++)
	{
		num[i] = start;
		start = start+1;
	}
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n-1;j++)
        {
            if(num[j]%num[i] == 0)
            {
                kha[index] = num[j];
                index++;
            }
        }
    }
    int index_2=index;
    for(i=0;i<index;i++)
    {
        for(j=i+1;j<index;j++)
        {
            if(kha[i] == kha[j] && kha[j]!=0)
            {
                kha[j] =0;
                index_2--;
            }
        }
    }
    int position_2=0;
    int num_2[index_2];
    for(i=0;i<index;i++)
    {
        if(kha[i]!=0)
        {
            num_2[position_2] = kha[i];
            position_2++;
        }
    }
    printf("%d",num_2[k-1]);
	return 0;
}
