#include <cstdio>
int arr[100001],qsum[100001],s[100001],e[100001];
int main(){
	int n,q,num;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		qsum[i] = qsum[i-1]+arr[i];
	}
	s[1] = 1;
	e[1] = qsum[1];
	for(int i=2;i<=n;i++){
		s[i] = qsum[i-1]+1;
		e[i] = qsum[i];
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&num);
		int left = 1,right = n,ans = -1;
		while(left <= right){
			int mid = (left+right)/2;
			if(s[mid] <= num && e[mid] >= num){
				ans = mid;
				break;
			}
			else if(s[mid] > num){
				right = mid-1;
			}
			else{
				left = mid+1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}