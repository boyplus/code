#include <cstdio>
int main(){
	int n,a,b,sum = 0;
	int min = 1e9;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		if(b < min){
			min = b;
		}
		sum = sum + (a*min);
	}
	printf("%d\n",sum);
	return 0;
}