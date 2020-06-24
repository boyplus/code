#include <cstdio>
#include <queue>
using namespace std;
char str[110][110] = {""};
queue<int> y,x,c;
bool chk[110][110];
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf(" %c",&str[i][j]);
		}
	}
	y.push(1);
	x.push(1);
	c.push(0);
	while(!y.empty()){
		int yy = y.front();
		int xx = x.front();
		chk[yy][xx] = true;
		if(yy == m && xx == n){
			printf("%d\n",c.front());
			return 0;
		}
		if(str[yy][xx-1] == '.' && !chk[yy][xx-1]){
			chk[yy][xx-1] = true;
			y.push(yy);
			x.push(xx-1);
			c.push(c.front()+1);
		}
		if(str[yy][xx+1] == '.' && !chk[yy][xx+1]){
			chk[yy][xx+1] = true;
			y.push(yy);
			x.push(xx+1);
			c.push(c.front()+1);
		}
		if(str[yy-1][xx] == '.' && !chk[yy-1][xx]){
			chk[yy-1][xx] = true;
			y.push(yy-1);
			x.push(xx);
			c.push(c.front()+1);
		}
		if(str[yy+1][xx] == '.' && !chk[yy+1][xx]){
			chk[yy+1][xx] = true;
			y.push(yy+1);
			x.push(xx);
			c.push(c.front()+1);
		}
		y.pop();
		x.pop();
		c.pop();
	}
	printf("-1\n");
	return 0;
}