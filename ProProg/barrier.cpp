#include <cstdio>
#include <limits.h>
#include <deque>
using namespace std;
long long arr[6000001];
deque< pair<long long,int> > win;
int main(){
	long long n,k,minK = INT_MAX,Max = -1;
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%lld",&arr[i]);
		arr[i]+=arr[i-1];
	}
	int index = 1 - k;
	for(int i = 1;i<=n;++i){
		while(!win.empty() && win.back().first >= arr[i]){
			win.pop_back();
		}
		win.push_back(make_pair(arr[i],i));
		while(win.front().second < index){
			win.pop_front();
		}
		long long temp = arr[i] - win.front().first;
		int tempK = i - win.front().second;
		if(temp > Max){
			Max = temp;
			minK = tempK; 
		}
		else if(temp == Max){
			if(tempK < minK){
				minK = tempK;
			}
		}
		++index;
	}
	if(Max == -1){
		printf("0\n0\n");
	}
	else{
		printf("%lld\n%lld\n",Max,minK);
	}
	return 0;
}