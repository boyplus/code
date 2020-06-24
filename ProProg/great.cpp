#include <cstdio>
#include <algorithm>
using namespace std;
struct graph
{
	int u;
	int v;
	long long dist;
} data[1000010];
int power[1000010],parent[1000010],high[1000010];
bool cmp(graph left,graph right)
{
	return left.dist < right.dist;
}
int main()
{
	int n,m,now_size=1,index=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&power[i]);
	scanf("%d",&m);
	for(int i=0; i<m; i++)
	{
		scanf("%d %d",&data[i].u,&data[i].v);
		data[i].dist = power[data[i].u] + power[data[i].v];
	}
	/*for(int i=1;i<=m;i++)
	{
		printf("%d to %d dist = %d\n",data[i].u,data[i].v,data[i].dist);
	}*/
	sort(data,data+m,cmp);
	///set default parent
	for(int i=1; i<=n; i++)
		parent[i] = i;
	///Kruskal's Algorithms
	long long sum = 0;
	while(now_size < n)
	{
		int u = data[index].u,v = data[index].v;
		int temp_u = u,temp_v = v;
		while(u != parent[u])
			u = parent[u];
		while(v != parent[v])
			v = parent[v];
		if(u!=v)
		{
			//printf("%d %d\n",temp_u,temp_v);
			if(high[u] > high[v])
				parent[v] = u;
			else
			{
				parent[u] = v;
				if(high[u] == high[v])
					high[v]++;
			}
			now_size++;
			sum = sum + data[index].dist;
		}
		index++;
	}
	printf("%lld\n",sum);
	return 0;
}