#include <cstdio>
#include <algorithm>
int arr[2000];
using namespace std;
int main(){
	int n,k,count=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n);
	for(int i=0;i<n-2;i++){
		if(arr[i]+k<=5 && arr[i+1]+k<=5 && arr[i+2]+k<=5){
			count++;
			i+=2;
		}
	}
	printf("%d\n",count);
	return 0;
}