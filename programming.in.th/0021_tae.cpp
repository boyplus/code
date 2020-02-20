#include <stdio.h>
#include <string.h>
int main()
{
	char msg[300];
	int i;
	gets(msg);
	int l=strlen(msg);
	int temp[l],co=0;
	for(i=0; i<l; i++)
		temp[i]=0;
	for(i=0; i<l-2; i++)
	{
		if(msg[i]==' ')
		{
			temp[i]=2;
		}
		else if(msg[i]==msg[i+2] && msg[i+1]=='p')
		{
			temp[i+1]=1;
			temp[i+2]=1;
		}
	}
	for(i=0; i<l; i++)
	{
		if(temp[i]==0)
			printf("%c",msg[i]);
		else if(temp[i]==2)
			printf(" ");
	}
}
