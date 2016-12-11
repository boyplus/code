#include <stdio.h>
int main()
{
	int a,b,c,sa,sb;
	scanf("%d %d %d",&a,&b,&c);
	sa=b-a;
	sb=c-b;
	if(sa>sb)
		printf("%d",sa-1);
	else if(sb>sa)
		printf("%d",sb-1);
	else
		printf("%d",sa-1);
}
