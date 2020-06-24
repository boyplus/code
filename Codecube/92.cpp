#include <cstdio>
#include <math.h>
double qsum[100010];
int main()
{
	int i,j,n,q,num;
	scanf("%d",&q);
	for(j=1;j<=100000;++j)
        qsum[j] = qsum[j-1] + log10(j);
	for(i=0;i<q;++i)
	{
		scanf("%d",&num);
		printf("%.0f\n",qsum[num]);
	}
	return 0;
}
