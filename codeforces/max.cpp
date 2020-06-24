#include <cstdio>
#include <algorithm>
using namespace std;
int arr[100000];
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	int min = 2e9,c=0;
	for(int i=k-1;i<n;i++){
		int temp = arr[i] - arr[c];
		//printf("in %d %d\n",i,c);
		if(temp < min){
			min = temp;
		}
		c++;
	}
	printf("%d\n",min);
	return 0;
}