#include<stdio.h>
int main()
{
	int i,a,num[5],temp=0;
	for(i=0;i<5;i++)
	{
		scanf("%d",&num[i]);
	}
    if(num[0] >num[1])
    {
        temp = num[0];
        num[0] = num[1];
        num[1] = temp;
    }
	return 0;
}
