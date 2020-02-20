#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	char assigment = '';
	char str[10]="";
	int num[26]={0};
	int i,j=0,k;
	int temp =0;
	char num_string[6] = "";
	int start=0;
	int end=0;
	while(1)
	{
		gets(str);
		int length = strlen(str);
		if(str[0] == '!')
		{
			break;
		}
		if(str[0] == '=')
		{
			for(i=65;i<91;i++)
			{
				if(i==str[2])
				{
					temp = i-65;
				}
			}
			start = 4;
			end = length;
			
			//num[temp] = 
		}
	}
	return 0;
}
/*
int A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0,I=0,J=0
,K=0,L=0,M=0,N=0,O=0,P=0,Q=0,R=0,S=0,T=0,U=0,
V=0,W=0,X=0,Y=0,Z=0;
*/