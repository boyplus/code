#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1000010;
int arr[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	int now = arr[1],sum = 0;
	for(int i=2;i<=n+1;i++){
		if(arr[i] < arr[i-1]){
			sum = sum + (arr[i-1]-now);
			now = arr[i];
		}
	}
	printf("%d\n",sum);
}