#include <stdio.h>
int main()
{
	int i,j,k,s,p,a,b;
	int num[9]={0};
	for(i=0;i<9;i++)
    {
        scanf("%d",&num[i]);
    }
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++)
		{
			for(k=j+1;k<5;k++)
			{
				for(s=k+1;s<6;s++)
				{
					for(p=s+1;p<7;p++)
					{
						for(a=p+1;a<8;a++)
						{
							for(b=a+1;b<9;b++)
							{
								if(num[i]+num[j]+num[k]+num[s]+num[p]+num[a]+num[b] == 100)
                                {
                                    printf("%d\n%d\n%d\n%d\n%d\n%d\n%d",num[i],num[j],num[k],num[s],num[p],num[a],num[b]);
                                    return 0;
                                }
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
