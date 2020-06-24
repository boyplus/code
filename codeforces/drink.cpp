#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	double num;
	double sum = 0,fre = 100.00*n;
	for(int i=0;i<n;i++){
		scanf("%lf",&num);
		sum+=num;
	}
	double ans = sum/fre;
	printf("%.10lf\n",ans*100.00);
	return 0;
}