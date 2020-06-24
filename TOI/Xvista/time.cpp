#include <cstdio>
int main(){
	int h,m,time;
	scanf("%d %d %d",&h,&m,&time);
	while(time--){
		m++;
		if(m>=60){
			m = 0;
			h++;
			if(h>23){
				h = 0;
			}
		}
	}
	if(h<10){
		printf("0%d ",h);
	}
	else{
		printf("%d ",h);
	}
	if(m<10){
		printf("0%d",m);
	}
	else{
		printf("%d",m);
	}
	printf("\n");
	return 0;
}