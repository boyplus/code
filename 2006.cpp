#include <cstdio>
#include <stdlib.h>
#include <time.h>
char rec[310][310];
int main()
{
    srand(time(NULL));
	int i,j,k,m,n;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%s",&rec[i]);
	}
	int max_size = m;
	if(n<m)
		max_size = n;
    printf("max = %d\n",max_size);
	for(i = max_size;i>=2;i--)
	{
		int rand_y = rand()%(m+1)- max_size+1;
		int rand_x = rand()%(n+1) - max_size+1;
		printf("%d %d\n",rand_y,rand_x);
	}
	return 0;
}
