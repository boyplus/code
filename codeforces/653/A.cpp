#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int x,y,n;
		scanf("%d %d %d",&x,&y,&n);
		int h = (n-y)/x;
		int ans = x*h+y;
		printf("%d\n",ans);
	}
	return 0;
}