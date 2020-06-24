#include <cstdio>
#include <queue>
int num[110][11000],m,n,k;
using namespace std;
int main()
{
	int i,j;
	scanf("%d %d %d",&m,&n,&k);
	for(i=1;i<=m;++i)
		for(j=1;j<=n;++j)
			scanf("%d",&num[i][j]);
	int max = 0;
	if(k==0)
	{
		for(int i=1;i<=n;++i)
		{
			int sum = 0;
			for (int j = 1; j <= m; ++j)
				sum = sum + num[j][i];
			if (sum > max)
				max = sum;
		}
		printf("%d",max);
		return 0;
	}
	for(i=m;i>=1;--i)
	{
		priority_queue <int> my_queue;
		int save[10001]={0};
		//in push priority queue
		int right = k+1;
		for(int a=1;a<=right;++a)
		{
			my_queue.push(num[i+1][a]);
			++save[num[i+1][a]];
		}
		num[i][1] = my_queue.top()+num[i][1];
		for(j=2;j<=n;++j)
		{
			if(j>k)
			{
				--save[num[i+1][j-k-1]];
				while(save[my_queue.top()]==0)
					my_queue.pop();
			}
			my_queue.push(num[i+1][j+k]);
			++save[num[i+1][j+k]];
			num[i][j] = my_queue.top()+num[i][j];
			
		}
	}
	for(int i=1;i<=n;++i)
		if(num[1][i] > max)
			max = num[1][i];
	printf("%d",max);
	return 0;
}