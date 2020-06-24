#include <cstdio>
#include <limits.h>
int arr[500010],n,k;
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	int index = 1,edge = 1,now=0;
	int temp = n-k;
	while(index < temp){
		///Add val
		int Min = INT_MAX,index_choose = 0;
		int temp2 = index+k;
		for(int i=edge+1;i<=temp2;i++){
			arr[i] = arr[i]+arr[index];
		}
		edge = index+k;
		///find min and choose index
		for(int i = index+1;i<=temp2;i++){
			if(arr[i] < Min){
				Min = arr[i];
				index_choose = i;
			}
		}
		index = index_choose;
	}
	printf("%d\n",arr[index]+arr[n]);
	return 0;
}