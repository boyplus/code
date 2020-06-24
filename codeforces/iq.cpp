#include <cstdio>
int main(){
	int n,num,even=0,le=1,lo=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		if(num%2){
			even--;
			lo = i;
		}
		else{
			even++;
			le = i;
		}
	}
	if(even > 0){
		printf("%d\n",lo);
	}
	else{
		printf("%d\n",le);
	}
	return 0;
}