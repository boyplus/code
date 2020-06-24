#include <cstdio>
#include <math.h>
int main(){
	double min = 9999999999999;
	int con,nCreate=1000,price=100,page=0,p=0;
	scanf("%d",&con);
	for(int i=nCreate;i<=15000;i+=500){
		int sell = 74;
		for(int j=74;j<=144;j++){
			double nSell;
			double D = j-100;
			nSell = ( (100 - (0.8569*exp(0.09*D) )) *i)/100.00;
			double raiDai = nSell*j;
			double total = con+(price*i);
			double kum = raiDai - total;
			if(kum > 0){
				if(kum < min){
					page = i;
					p = j;
					min = kum;
				}
			}
		}
		price--;
	}
	printf("%d\n%d\n%.2lf\n",page,p,min);
	return 0;
}