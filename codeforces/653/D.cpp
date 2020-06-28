#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		vector<int> vec;
		vec.clear();
		int n,k,x;
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++){
			scanf("%d",&x);
			vec.push_back(x);
		}
		sort(vec.begin(),vec.end());
		int nowX = 0,nowK = k;
		for(int i=vec.size()-1;i>=0;i--){
			int r = vec[i]%nowK;
			if(vec[i] > nowK){
				int temp = vec[i]
			}
		}
	}
	return 0;
}