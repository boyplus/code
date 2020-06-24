#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
int m,n,num,arr[510][510],co[510];
bool mp[510][510],visited[510][510];
class grid{
public:
	int y,x,count;
	grid(int y,int x,int count){
		this->y = y;
		this->x = x;
		this->count = count;
	}
};
queue<grid> q;
int main(){
	int max = 0,now=0;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&num);
			mp[i][j] = !num;
		}
	}
	///BFS
	int movey[4] = {-1,-1,0,0};
	int movex[4] = {0,0,1,1};
	q.push(grid(m,1,0));
	visited[m][1] = true;
	while(!q.empty()){
		int yy = q.front().y;
		int xx = q.front().x;
		int cc = q.front().count;
		arr[yy][xx] = cc;
		if(cc > max){
			max = cc;
		}
		for(int i=0;i<4;i++){
			if(mp[yy+movey[i]][xx+movex[i]] == 1 && visited[yy+movey[i]][xx+movex[i]] == false){
				visited[yy+movey[i]][xx+movex[i]] = true;
				q.push(grid(yy+movey[i],xx+movex[i],cc+1));
			}
		}
		q.pop();
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j] && arr[i][j] <= max){
				co[arr[i][j]]++;
			}
		}
	}
	int sum = 0;
	for(int i=1;i<=max;i++){
		sum = sum + (co[i]*co[i]);
	}
	printf("%d\n",sum+1);
	return 0;
}