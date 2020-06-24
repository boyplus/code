#include <cstdio>
int Min(float a,float b,float c){
	int Mn = a;
	if(b < Mn)
		Mn = b;
	if(c < Mn)
		Mn = c;
	return Mn;
}
int main(){
	float n,k,l,c,d,p,nl,np;
	scanf("%f %f %f %f %f %f %f %f",&n,&k,&l,&c,&d,&p,&nl,&np);
	float x = k*l/nl,y = c*d,z = p/np;
	printf("%d\n",Min(x,y,z)/(int)n);
	return 0;
}
//n,k,l,c, d, p, nl, np
//3 4 5 10 8 100 3   1