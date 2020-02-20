#include <stdio.h>
int main()
{
	int i,j,k,n,energy;
	scanf("%d",&energy);
	int num;
	int temp_energy = energy*2;
	int energy_even = energy;
	int energy_odd = energy;
	int count_even=0;
	int count_odd=0;
	for(i=0;i<temp_energy;++i)
	{
		scanf("%d",&num);
		if(num%2==0)
		{
			++count_even;
			count_odd=0;
			if(count_even >=3)
				energy_odd-=3;
			else
				--energy_odd;
			if(energy_odd <=0)
			{
				printf("0\n");
				printf("%d",num);
				return 0;
			}
		}
		else
		{
			++count_odd;
			count_even=0;
			if(count_odd>=3)
				energy_even-=3;
			else
				--energy_even;
			if(energy_even <=0)
			{
				printf("1\n");
				printf("%d",num);
				return 0;
			}
		}
	}
	return 0;
}
