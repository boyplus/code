#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	double result;
	int len,i;
	float num,x=0,y=0;
	char input[100],temp[100];
	scanf("%s",input);
	while(input[0]!='*')
	{
		len=strlen(input);
		for(i=0; i<len; i++)
		{
			if(input[i] >=65 && input[i]<=90)
			{
				strcpy(temp,input);
				input[i]='\0';
				num=atoi(input);
				if(temp[i]=='N' && temp[i+1]=='\0')
				{
					y=y+num;
				}
				else if(temp[i]=='S' && temp[i+1]=='\0')
				{
					y=y-num;
				}
				else if(temp[i]=='E' && temp[i+1]=='\0')
				{
					x=x+num;
				}
				else if(temp[i]=='W' && temp[i+1]=='\0')
				{
					x=x-num;
				}
			}
		}
		scanf("%s",input);
	}
	result=sqrt(pow(x,2)+pow(y,2));
	printf("%.3f %.3f\n%.3f",x,y,result);
}
