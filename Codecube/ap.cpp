#include <cstdio>
#define LL long long
int n,arr[601];
LL dp[601][601];
LL max(LL a,LL b){
	if(a>b){
		return a;
	}
	return b;
}
LL min(LL a,LL b){
	if(a<b){
		return a;
	}
	return b;
}
LL rec(int left,int right){
	if(left >= right){
		return 0;
	}
	///calculate sum 1
	LL sumLeft1 = arr[left];
	LL sumRight1 = 0;
	for(int i=left+1;i<=right;i++){
		sumRight1+=arr[i];
	}
	LL max1 = max(sumLeft1,sumRight1),min1 = min(sumLeft1,sumRight1);
	///calculate sum 2
	LL sumLeft2 = 0;
	LL sumRight2 = arr[right];
	for(int i=left;i<right;i++){
		sumLeft2+=arr[i];
	}
	LL max2 = max(sumLeft2,sumRight2),min2 = min(sumLeft2,sumRight2);
	LL all1 = (min1*2)+(max1);
	LL all2 = (min2*2)+(max2);
	LL ans1=0,ans2=0;
	if(dp[left+1][right]!=0){
		ans1 = dp[left+1][right];
	}
	else{
		dp[left+1][right] = ans1 = rec(left+1,right);
	}
	if(dp[left][right-1]!=0){
		ans2 = dp[left][right-1];
	}
	else{
		dp[left][right-1] = ans2 = rec(left,right-1);
	}
	return max(all1+ans1,all2+ans2);
	
	
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	LL ans = rec(1,n);
	printf("%lld\n",ans);
	return 0;
}