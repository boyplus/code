#include <cstdio>
using namespace std;
int main()
{
	int dat[3],max=-1,c=0;
	scanf("%d %d %d",&dat[0],&dat[1],&dat[2]);
	if(dat[0]+dat[1]+dat[2]!=100)
	{
		printf("BUG");
	}
	for(int i=0; i<3; i++)
		if(dat[i]>max)
			max=dat[i];
	for(int i=0; i<3; i++)
		if(max==dat[i])
			c++;
	if(c==1)
	{
		if(dat[0]==max)
			printf("PAPER");
		else if(dat[1]==max)
			printf("SCISSORS");
		else
			printf("ROCK");
	}
	else if(c>1)
		printf("I DON'T KNOW");
}
