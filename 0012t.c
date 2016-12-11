#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[20],ch[]={'#','*'};
	int i,j,m=0,k=0;

	gets(str);

	for(i=0;i<5;i++)
	{
		for(j=0;j<(strlen(str)*4)+1;j++)
		{
			if(j%12>=8 || j%12==0 && j!=0)
				k=1;

			if(i==0 || i==4)
			{
				if((j+1)%4==3)
					printf("%c",ch[k]);
				else
					printf(".");
			}

			if(i==1 || i==3)
			{
				if(j%2==0)
					printf(".");
				else
					printf("%c",ch[k]);
			}

			if(i==2)
			{
				if((j+1)%4==1)
					printf("%c",ch[k]);
				if((j+1)%4==2)
					printf(".");
				if((j+1)%4==3)
				{
					printf("%c",str[m]);
					m++;
				}
				if((j+1)%4==0)
					printf(".");
			}
			k=0;
		}
		printf("\n");
	}
}
