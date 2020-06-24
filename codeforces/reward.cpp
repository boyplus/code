#include <cstdio>
#include <math.h>
int main(){
	int n;
	double a[1000] = {0},b[1000] = {0},cup=0,medal = 0;
	for(int i=0;i<3;i++){
		scanf("%lf",&a[i]);
		cup = cup+a[i];
	}
	for(int i=0;i<3;i++){
		scanf("%lf",&b[i]);
		medal = medal+b[i];
	}
	scanf("%d",&n);
	int temp = ceil((cup/5.00)) + ceil((medal/10.00));
	if(temp > n){
		printf("NO\n");
	}
	else{
		printf("YES\n");
	}
	return 0;
}