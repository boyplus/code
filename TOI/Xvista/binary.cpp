#include <cstdio>
int num[100000];
int main(){
	int n,m,want;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	while(m--){
		scanf("%d",&want);
		int left = 0,right = n;
		bool chk = false;
		while(left <= right){
			int mid = (left+right)/2;
			if(num[mid] == want){
				printf("%d\n",want);
				chk = true;
				break;
			}
			else if(num[mid] > want){
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
		if(chk == true){
			continue;
		}
		int mid = (left+right)/2;
		if(mid >= n){
			mid = n-1;
		}
		if(num[mid] <= want){
			printf("%d\n",num[mid]);
		}
		else{
			printf("-1\n");
		}
	}
	return 0;
}