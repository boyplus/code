#include <cstdio>
int tem[21][21],max=-1;
void walk(int i,int j);
int main()
{
	int i,j,k,n,m,y,x;
	scanf("%d %d %d",&n,&y,&x);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&tem[i][j]);
	walk(x,y);
	printf("%d",max);
	return 0;
}
void walk(int i,int j)
{
	if(tem[i][j] > max)
		max = tem[i][j];
	if(tem[i][j-1]>tem[i][j]&&tem[i][j-1]!=100)
		walk(i,j-1);
	if(tem[i][j+1]>tem[i][j]&&tem[i][j+1]!=100)
		walk(i,j+1);
	if(tem[i+1][j] > tem[i][j] && tem[i+1][j]!=100)
		walk(i+1,j);
	if(tem[i-1][j] > tem[i][j] && tem[i-1][j]!=100)
		walk(i-1,j);
}
