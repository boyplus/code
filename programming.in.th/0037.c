#include <stdio.h>
int main()
{
	int i,j,k,n,l,c,m;
	scanf("%d %d",&n,&m);
	scanf("%d %d",&l,&k);
	scanf("%d",&c);
	int num[n][m];
	int sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&num[i][j]);
			sum = sum+num[i][j];
		}
	}
	sum = sum+(l*k*c);
	while(sum%c!=0)
	{
        ++sum;
	}
	printf("%d\n",sum/c);
    return 0;
}
