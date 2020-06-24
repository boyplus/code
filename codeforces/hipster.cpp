#include <cstdio>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	int min = a,max = a;
	if(b < min){
		min = b;
	}
	if(b > max){
		max = b;
	}
	printf("%d %d\n",min,(max-min)/2);
	return 0;
}