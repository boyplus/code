#include<stdio.h>
int main()
{
	long red,green;
	scanf("%d %d",&red,&green);
	unsigned int i,a;
	long max;
	if(red > green)
		max = green;
	else
		max = red;
	unsigned int b=1;
	printf("%d %d %d\n",1,red,green);
	for(i=2;i<=max;++i)
	{
		if(red%i == 0)
		{
		    if(green%i==0)
            {
                printf("%d %d %d\n",i,red/i,green/i);
            }
		}
	}
	return 0;
}
//1000000000 1000000000
