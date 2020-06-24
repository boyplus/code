#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
queue<int> q;
int arr[100000];
int main(){
	int n,k,Max=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	int index = 0,sum=0,size=0,first = 0;
	while(index < n){
		while(sum + arr[index] <= k && index < n){
			size++;
			sum = sum+arr[index];
			index++;
			if(size > Max){
				Max = size;
			}
		}
		sum = sum - arr[first];
		first++;
		size--;
	}
	printf("%d\n",Max);
	return 0;
}