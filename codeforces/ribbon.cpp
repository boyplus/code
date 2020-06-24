#include <cstdio>
int n,l[20];
int max(int a,int b){
	if(a>b){
		return a;
	}
	return b;
}
int rec(int length,int index){
	printf("in cal %d\n",length);
	if(length <=0){
		return 0;
	}
	int ans = 0;
	for(int i=index;i<=3;i++){
		if(l[i] < length){
			return max( rec(l[i],i)+1 , rec(length,i+1));
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=3;i++){
		scanf("%d",&l[i]);
	}
	int ans = rec(n,1);
	printf("%d\n",ans);
	return 0;
}