#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int maxm = 2005,maxn = 2005;
int arr[maxm][maxn];
bool visited[maxm][maxn];
int dy[4] = {0,0,1,-1};
int dx[4] = {1,-1,0,0};
class grid{
public:
	int y,x,cnt;
	grid(int y,int x,int cnt){
		this->y = y;
		this->x = x;
		this->cnt = cnt;
	}
};
int main(){
	int m,n;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	if(arr[1][1]%2 == 0){
		printf("-1\n");
		return 0;
	}
	queue<grid> q;
	q.push(grid(1,1,0));
	visited[1][1] = true;
	while(!q.empty()){
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();
		if(y == m && x == n){
			printf("%d\n",cnt);
			return 0;
		}
		for(int i=0;i<4;i++){
			int yy = y+dy[i],xx = x+dx[i];
			if(arr[yy][xx]%2 == 0 || visited[yy][xx] == true) continue;
			visited[yy][xx] = true;
			q.push(grid(yy,xx,cnt+1));
		}
	}
	printf("-1\n");
	return 0;
}