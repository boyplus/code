#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
bool mp[1010][1010];
int fre[1010][1010];
class grid{
public:
	int y,x,count;
	grid(int y,int x,int count){
		this->y = y;
		this->x = x;
		this->count = count;
	}
};
class cmp{
public:
	bool operator()(const grid& left,const grid& right){
		return left.count > right.count;
	}
};
priority_queue<grid,vector<grid> , cmp > q;
bool cmp(const grid& left,const grid& right){
	return left.count < right.count;
}
int main(){
	int n,s,min = 1e9;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&s);
			mp[i][j] = s;
			fre[i][j] = 1e9;
		}
	}
	if(n == 1){
		printf("0\n");
		return 0;
	}
	q.push(grid(1,1,0));
	fre[1][1] = 0;
	while(!q.empty()){
		int y = q.top().y,x = q.top().x,def_count=q.top().count;
		q.pop();
		int nowY = y,nowX = x,count = def_count;
		///trav right
		while(nowX < n && mp[nowY][nowX+1] == 0){
			nowX++;
			count++;
			if(nowX == n && nowY == n){
				if(count < min){
					min = count;
				}
			}
		}
		if(count < fre[nowY][nowX]){
			fre[nowY][nowX] = count;
			q.push(grid(nowY,nowX,count));
		}
		nowY = y;
		nowX = x;
		count = def_count;

		///trav left
		while(nowX > 1 && mp[nowY][nowX-1] == 0){
			nowX--;
			count++;
			if(nowX == n && nowY == n){
				if(count < min){
					min = count;
				}
			}
		}
		if(count < fre[nowY][nowX]){
			fre[nowY][nowX] = count;
			q.push(grid(nowY,nowX,count));
		}
		nowY = y;
		nowX = x;
		count = def_count;

		///trav down
		while(nowY < n && mp[nowY+1][nowX] == 0){
			nowY++;
			count++;
			if(nowX == n && nowY == n){
				if(count < min){
					min = count;
				}
			}
		}
		if(count < fre[nowY][nowX]){
			fre[nowY][nowX] = count;
			q.push(grid(nowY,nowX,count));
		}
		nowY = y;
		nowX = x;
		count = def_count;

		///trav up
		while(nowY > 1 && mp[nowY-1][nowX] == 0){
			nowY--;
			count++;
			if(nowX == n && nowY == n){
				if(count < min){
					min = count;
				}
			}
		}
		if(count < fre[nowY][nowX]){
			fre[nowY][nowX] = count;
			q.push(grid(nowY,nowX,count));
		}
		nowY = y;
		nowX = x;
		count = def_count;
	}
	printf("%d\n",min);
	return 0;
}