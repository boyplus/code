#include <stdio.h>
#include <string.h>
int main()
{
	char input[101];
	gets(input);
	int i,j,k;
	int length = strlen(input);
	for(i=0;i<length;i++)
	{
		if(input[i] == 'a' && input[i+1] == 'p' && input[i+2] == 'a')
		{
			for(j=i;j<length;j++)
			{
				input[j] = input[j+2];
			}
		}
		if(input[i] == 'e' && input[i+1] == 'p' && input[i+2] == 'e')
		{
			for(j=i;j<length;j++)
			{
				input[j] = input[j+2];
			}
		}
		if(input[i] == 'i' && input[i+1] == 'p' && input[i+2] == 'i')
		{
			for(j=i;j<length;j++)
			{
				input[j] = input[j+2];
			}
		}
		if(input[i] == 'o' && input[i+1] == 'p' && input[i+2] == 'o')
		{
			for(j=i;j<length;j++)
			{
				input[j] = input[j+2];
			}
		}
		if(input[i] == 'u' && input[i+1] == 'p' && input[i+2] == 'u')
		{
			for(j=i;j<length;j++)
			{
				input[j] = input[j+2];
			}
		}
	}
	printf("%s\n",input);
	return 0;
}
