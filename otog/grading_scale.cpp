#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100005;
vector<int> vec;
int main(){
	int n,q,t,l,r;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		vec.push_back(t);
	}
	sort(vec.begin(),vec.end());
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d %d",&l,&r);
		if(l > r){
			int temp = l;
			l = r;
			r = temp;
		}
		int pos1 = lower_bound (vec.begin(), vec.end(),l)-vec.begin();
		int pos2 = upper_bound(vec.begin(),vec.end(),r)-vec.begin();
		printf("%d\n",pos2 - pos1);
	}
    return 0;
}