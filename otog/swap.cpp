#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100005;
int arr[maxn];
int main(){
	int n,m,a,b;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	while(m--){
		scanf("%d %d",&a,&b);
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
    return 0;
}