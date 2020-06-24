#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int num[100001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	for(int i=0;i<n;i++){
		if(num[i] != i+1){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}