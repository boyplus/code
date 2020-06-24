#include <cstdio>
#include <queue>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
const int N = 200;
bool num[N][N],chk1[N][N],boom1[N][N],chk2[N][N],boom2[N][N];
vector<int> saveY,saveX;
int m,n,sy,sx,ey,ex,temp;
void Trav1(int,int);
void Trav2(int,int);
int main(){
	scanf("%d %d %d %d %d %d",&m,&n,&sy,&sx,&ey,&ex);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&temp);
			num[i][j] = temp;
		}
	}
	Trav1(sy,sx);
	Trav2(ey,ex);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			bool boom = boom1[i][j]&boom2[i][j];
			if(boom == true){
				saveY.push_back(i);
				saveX.push_back(j);
			}
		}
	}
	int vecSize = saveY.size(),min = INT_MAX;
	for(int i=0;i<vecSize;i++){
		num[saveY[i]][saveX[i]] = true;
		///BFS to find shortest path
		queue<int> y,x,c;
		y.push(sy);
		x.push(sx);
		c.push(0);
		bool visited[N][N] = {false};
		while(!y.empty()){
			int yy = y.front();
			int xx = x.front();
			visited[yy][xx] = true;
			if(yy == ey && xx == ex){
				if(c.front() < min){
					min = c.front();
					break;
				}
			}
			if(num[yy][xx-1] && !visited[yy][xx-1] && xx-1>=1){
				visited[yy][xx-1] = true;
				y.push(yy);
				x.push(xx-1);
				c.push(c.front()+1);
			}
			if(num[yy][xx+1] && !visited[yy][xx+1] && xx+1 <=n){
				visited[yy][xx+1] = true;
				y.push(yy);
				x.push(xx+1);
				c.push(c.front()+1);
			}
			if(num[yy-1][xx] && !visited[yy-1][xx] && yy-1>=1){
				visited[yy-1][xx] = true;
				y.push(yy-1);
				x.push(xx);
				c.push(c.front()+1);
			}
			if(num[yy+1][xx] && !visited[yy+1][xx] && yy+1 <=m){
				visited[yy+1][xx] = true;
				y.push(yy+1);
				x.push(xx);
				c.push(c.front()+1);
			}
			y.pop();
			x.pop();
			c.pop();
		}
		num[saveY[i]][saveX[i]] = false;
	}
	printf("%d\n%d\n",vecSize,min+1);
	return 0;
}
void Trav1(int y,int x){
	chk1[y][x] = true;
	///boom
	if(!num[y][x-1] && x-1>=1)
		boom1[y][x-1] = true;
	if(!num[y][x+1] && x+1<=n)
		boom1[y][x+1] = true;
	if(!num[y-1][x] && y-1>=1)
		boom1[y-1][x] = true;
	if(!num[y+1][x] && y+1<=m)
		boom1[y+1][x] = true;
	///trav
	if(num[y][x-1] && x-1>=1 && !chk1[y][x-1])
		Trav1(y,x-1);
	if(num[y][x+1] && x+1<=n && !chk1[y][x+1])
		Trav1(y,x+1);
	if(num[y-1][x] && y-1>=1 && !chk1[y-1][x])
		Trav1(y-1,x);
	if(num[y+1][x] && y+1<=m && !chk1[y+1][x])
		Trav1(y+1,x);
}
void Trav2(int y,int x){
	chk2[y][x] = true;
	///boom
	if(!num[y][x-1] && x-1>=1)
		boom2[y][x-1] = true;
	if(!num[y][x+1] && x+1<=n)
		boom2[y][x+1] = true;
	if(!num[y-1][x] && y-1>=1)
		boom2[y-1][x] = true;
	if(!num[y+1][x] && y+1<=m)
		boom2[y+1][x] = true;
	///trav
	if(num[y][x-1] && x-1>=1 && !chk2[y][x-1])
		Trav2(y,x-1);
	if(num[y][x+1] && x+1<=n && !chk2[y][x+1])
		Trav2(y,x+1);
	if(num[y-1][x] && y-1>=1 && !chk2[y-1][x])
		Trav2(y-1,x);
	if(num[y+1][x] && y+1<=m && !chk2[y+1][x])
		Trav2(y+1,x);
}