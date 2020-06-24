#include <cstdio>
int fre[1500];
int main(){
	int T,h,m,max=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&h,&m);
		int num = (h*60)+m;
		fre[num]++;
		if(fre[num] > max){
			max = fre[num];
		}
	}
	printf("%d\n",max);
	return 0;
}