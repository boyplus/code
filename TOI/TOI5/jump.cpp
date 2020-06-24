#include <cstdio>
int num[30000];
int main(){
	int n,k,max=0;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	for(int i=0;i<n;i++){
		int want = num[i]+k;
		///Binary Search
		int left = 0,right = n;
		bool chk = false;
		while(left<=right){
			int mid = (left+right)/2;
			if(num[mid] == want){
				int temp = mid - i;
				if(temp > max){
					max = temp;
				}
				chk = true;
				break;
			}
			if(num[mid] > want){
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
		if(chk == false){
			if(left > n){
				left = n;
			}
			int temp = left - i-1;
			if(temp > max){
				max = temp;
			}
		}
	}
	printf("%d\n",max);
	return 0;
}