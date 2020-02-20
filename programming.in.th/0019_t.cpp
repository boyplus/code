#include <cstdio>
#include <limits.h>
struct candy
{
	int s;
	int b;
}data[10];
void make(int,int,int);
int n,min = INT_MAX;
bool save[10] = {false};
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d %d",&data[i].s,&data[i].b);
	make(1,0,0);
	printf("%d\n",min);
	return 0;
}
void make(int sum_s,int sum_b,int count)
{
    if(min==0)
        return;
	int num = sum_s - sum_b;
	if(num < 0)
		num*=-1;
	if(num < min && count)
		min = num;
	for(int i=0;i<n;++i)
	{
		if(!save[i])
		{
			save[i] = true;
			make(sum_s*data[i].s,sum_b+data[i].b,count+1);
			save[i] = false;
		}
	}
}
