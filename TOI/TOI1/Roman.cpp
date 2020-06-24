#include <cstdio>
int c1,c5,c10,c50,c100;
void solve(int num){
	int n1=0,n5=0,n10=0,n50=0,n100=0;
	if(num>=100){
		int temp = num/100;
		n100 = n100+temp;
		num = num - (temp*100);
	}
	if(num>=90){
		n100++;
		n10++;
		num = num - 90;
	}
	if(num>=50){
		n50++;
		num = num - 50;
	}
	if(num>=40){
		n50++;
		n10++;
		num = num - 40;
	}
	if(num >= 10){
		int temp = num/10;
		n10 = n10 + temp;
		num = num - (temp*10);
	}
	if(num>=9){
		n10++;
		n1++;
		num-=9;
	}
	if(num>=5){
		n5++;
		num-=5;
	}
	if(num>=4){
		n5++;
		n1++;
		num-=4;
	}
	if(num>=1){
		n1+=num;
	}
	c1+=n1;
	c5+=n5;
	c10+=n10;
	c50+=n50;
	c100+=n100;
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		solve(i);
	}
	printf("%d %d %d %d %d\n",c1,c5,c10,c50,c100);
	return 0;
}