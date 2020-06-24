#include <cstdio>
int main(){
	int n,d,sum = 0,t;
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		sum = sum+t;
	}
	int rest = (n-1)*10;
	if(rest+sum <= d){
		int temp = rest/10;
		int remain = (d - (temp*10) - sum)/5;
		printf("%d\n",temp*2+remain);
	}
	else{
		printf("-1\n");
	}
	return 0;
}