#include <cstdio>
#include <limits.h>
#include <vector>
using namespace std;
long long dp[2000002],Max = INT_MIN;
vector<long long> s,e;
int main(){
	long long n,m,a,b;
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld %lld",&a,&b);
		dp[a]++;
		dp[b+1]--;
		if(b > Max){
			Max = b;
		}
	}
	for(int i=1;i<=Max;i++){
		dp[i] = dp[i-1] + dp[i];
	}
	for(int i=1;i<=Max;i++){
		if(dp[i] == m){
			s.push_back(i);
			for(int j=i;j<=Max+1;j++){
				if(dp[j] != m){
					i = j;
					e.push_back(j-1);
					break;
				}
			}
		}
	}
	int vecSize = s.size();
	for(int i=0;i<vecSize;i++){
		printf("%lld %lld\n",s[i],e[i]);
	}
	return 0;
}