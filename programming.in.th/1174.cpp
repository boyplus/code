#include <cstdio>
#include <limits.h>
struct position
{
	int x;
	int y;
	int z;
	int n_m; //monitor
	int n_k; //keyboard
	int n_c; //case
}data[10];
void Trav(int,int,int,int,int,int,int);
int n,market,min = INT_MAX;
bool save[10] = {false};
int main()
{
	int i,j,k,x,y,z;
	scanf("%d",&n);
	scanf("%d %d %d",&x,&y,&z);
	scanf("%d",&market); //n of market
	for(i=0;i<market;++i)
	{
		scanf("%d %d %d",&data[i].x,&data[i].y,&data[i].z);
		scanf("%d %d %d",&data[i].n_m,&data[i].n_k,&data[i].n_c);
	}
	Trav(x,y,z,0,0,0,0);
	printf("%d\n",min);
	return 0;
}
void Trav(int x,int y,int z,int m,int k,int c,int pay)
{
	if(m>=n && k>=n && c>=n)
	{
		if(pay < min)
			min = pay;
	}
	else
	{
		for(int i=0;i<market;++i)
		{
			if(!save[i])
			{
			    int num1 = (x-data[i].x);
			    int num2 = (y-data[i].y);
			    int num3 = (z-data[i].z);
				int cost = num1*num1 + num2*num2 + num3*num3;
				save[i] = true;
				Trav(data[i].x,data[i].y,data[i].z,m+data[i].n_m,k+data[i].n_k,c+data[i].n_c,cost+pay);
				save[i] = false;
			}

		}
	}
}
