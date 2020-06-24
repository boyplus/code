#include <cstdio>
int f(int a){
	if(a<0){
		return -a;
	}
	return a;
}
int min(int a,int b){
	if(a<b)
		return a;
	return b;
}
int main(){
	int n,sum=0;
	char s1[2000],s2[2000];
	scanf("%d %s %s",&n,s1,s2);
	for(int i=0;i<n;i++){
		int num1 = s1[i]-48;
		int num2 = s2[i]-48;
		int w1 = f(num1-num2);
		int w2 = num1+(9-num2+1);
		int w3 = (9-num1+1)+num2;
		int ans = min(w1,w2);
		ans = min(ans,w3);
		//printf("ans = %d\n",ans);
		sum+=ans;
	}
	printf("%d\n",sum);
	return 0;
}