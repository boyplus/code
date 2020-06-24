#include <cstdio>
int num[110];
long long mem[110][110];
long long min(long long a,long long b){
	if(a < b){
		return a;
	}
	return b;
}
long long MCM(int left,int right){
	if(left == right){
		return 0;
	}
	if(mem[left][right] > 0){
		return mem[left][right];
	}
	mem[left][right] = 9999999999;
	for(int k = left;k<=right-1;k++){
		mem[left][right] = min(mem[left][right],MCM(left,k) + MCM(k+1,right) + num[left-1]*num[k]*num[right]);
	}
	return mem[left][right];
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		scanf("%d",&num[i]);
	}
	long long ans = MCM(1,n);
	printf("%lld\n",ans);
	return 0;
}