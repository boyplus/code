#include <cstdio>
#include <vector>
#include <limits.h>
using namespace std;
vector<int> vec[1000000];
int main(){
	int T,n,N,num,k;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&n);
		int temp = INT_MIN;
		for(int j=0;j<n;j++){
			scanf("%d",&num);
			if(num != temp){
				vec[i].push_back(num);
			}
			temp = num;
		}
	}
	scanf("%d",&k);
	for(int i=0;i<N;i++){
		if(k > vec[i].size()){
			printf("-1\n");
		}
		else{
			printf("%d\n",vec[i][k-1]);
		}
	}
	return 0;
}