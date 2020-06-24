///Tutorail
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int arr[2000],dp[2000],Prev[2000];
vector<int> LIS,idx;
int main(){
	/*
		Increasing (lower_boundn) >=
		Decreasing (upper_bound) >
	*/
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<=n;i++){
		int pos = lower_bound(LIS.begin(),LIS.end(),arr[i]) - LIS.begin();
		if(pos == LIS.size()){
			LIS.push_back(arr[i]);
			idx.push_back(i);
		}
		else{
			LIS[pos] = arr[i];
			idx[pos] = i;
		}
		if(pos !=0 ){
			Prev[i] = idx[pos-1];
		}
		dp[i] = pos+1;
	}
	printf("%d\n",(int)LIS.size());
	printf("in vec : ");
	for(int i=0;i<LIS.size();i++){
		printf("%d ",LIS[i]);
	}
	printf("\n in DP : ");
	for(int i=1;i<=n;i++){
		printf("%d ",dp[i]);
	}
	printf("\n");
	return 0;
}