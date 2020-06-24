#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1000000];
vector<int> LIS;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;++i){
		int pos = lower_bound(LIS.begin(),LIS.end(),arr[i]) - LIS.begin();
		if(pos == LIS.size()){
			LIS.push_back(arr[i]);
		}
		else{
			LIS[pos] = arr[i];
		}
	}
	printf("%d\n",n - (int)LIS.size());
	return 0;
}