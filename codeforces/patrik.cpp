#include <cstdio>
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int t1 = a+b+c;
	int t2 = (2*a)+(2*b);
	int t3 = 2*a+2*c;
	int t4 = 2*b + 2*c;
	int min = t1;
	if(t2 < min)
		min = t2;
	if(t3 < min)
		min = t3;
	if(t4 < min)
		min = t4;
	printf("%d\n",min);
	return 0;
}