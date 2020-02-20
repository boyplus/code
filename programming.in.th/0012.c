#include <stdio.h>
#include <string.h>
int main()
{
	char str[20]="";
	gets(str);
	int i,j,k,l;
	int length = strlen(str);
	int time_print = length;
	for(i=1;i<=time_print;i++)
	{
		
		if(i%3==0)
		{
			printf("..*..");
		}
		else
		{
			printf("..#..");
		}
	}
	for(i=1;i<=time_print*2;i++)
	{
		if(i%5==0||i%6==0)
		{
			printf("");
		}
	}

	return 0;
}