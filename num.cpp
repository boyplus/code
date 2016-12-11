#include <cstdio>
int n,k,count_all=0;
void make(int);
int ans[10];
bool use[10];
int main()
{
	int i,j;
	scanf("%d %d",&n,&k);
	make(0);
	return 0;
}
void make(int count)
{
	if(count == n)
	{
		++count_all;
		if(count_all == k)
			for(int i=0;i<n;++i)
				printf("%d",ans[i]);
	}
	else
	{
		for(int i=1;i<=n;++i)
		{
			if(!use[i])
			{
				use[i] = true;
				ans[count] = i;
				make(count+1);
				use[i] = false;
			}
		}
	}
}
