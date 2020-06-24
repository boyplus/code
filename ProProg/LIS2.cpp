#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
int arr[200000],dp[200000],Prev[200000];
vector<int> LIS,idx;
stack<int> ans;
int main(){
	/*
		Increasing (lower_boundn) >=
		Decreasing (upper_bound) >
	*/
	int n=0,index=1,temp;
	while(scanf("%d",&temp) != EOF){
		arr[index] = temp;
		n++;
		index++;
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
	printf("%d\n-\n",(int)LIS.size());
	int vecSize = LIS.size();
	int now = idx[vecSize-1];
	for(int i=0;i<vecSize;i++){
		int num = arr[now];
		ans.push(num);
		now = Prev[now];
	}
	while(!ans.empty()){
		printf("%d\n",ans.top());
		ans.pop();
	}
	return 0;
}