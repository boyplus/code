#include <cstdio>
#include <algorithm>
using namespace std;
long long num[3000];
int main()
{
	int i,j,n,temp_n;
	scanf("%d",&n);
	temp_n = n*2;
	int last = temp_n-1;
	for(i=0;i<n;i++)
		scanf("%lld",&num[i]);
	for(i=n;i<temp_n;i++)
		scanf("%lld",&num[i]);
	sort(num,num+temp_n);
    long long sum = 0;
    for(i=0;i<n;i++,last--)
        sum = sum + (num[i]*num[last]);
    printf("%lld",sum);
	return 0;
}
