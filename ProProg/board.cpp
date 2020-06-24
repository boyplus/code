#include <cstdio>
#include <queue>
using namespace std;
int m,n,mp[600][600] = {0},sy,sx,ey,ex;
char temp;
class graph{
public:
	int y,x,dis;
	bool a,b,c;
	graph(int y,int x,int dis,bool a,bool b,bool c){
		this->y = y;
		this->x = x;
		this->dis = dis;
		this->a = a;
		this->b = b;
		this->c = c;
	}
};
queue<graph> q;
bool chk[600][600][2][2][2] = {false};
int main(){
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf(" %c",&temp);
			if(temp == 'S'){
				mp[i][j] = 1;
				sy = i;
				sx = j;
			}
			else if(temp == 'E'){
				mp[i][j] = 5;
				ey = i;
				ex = j;
			}
			else if(temp == '.'){
				//printf("eiei %d %d\n",i,j);
				mp[i][j] = 1;
			}
			else if(temp == 'J')
				mp[i][j] = 2;
			else if(temp == 'B')
				mp[i][j] = 3;
			else if(temp == 'P')
				mp[i][j] = 4;
			else if(temp == 'j')
				mp[i][j] = -2;
			else if(temp == 'b')
				mp[i][j] = -3;
			else if(temp == 'p')
				mp[i][j] = -4;
		}
	}
	chk[sy][sx][false][false][false] = true;
	q.push(graph(sy,sx,0,false,false,false));
	while(!q.empty()){
		int yy = q.front().y;
		int xx = q.front().x;
		int d = q.front().dis;
		bool a = q.front().a;
		bool b = q.front().b;
		bool c = q.front().c;
		q.pop();
		int py[4] = {0,0,1,-1};
		int px[4] = {1,-1,0,0};
		///End
		for(int i=0;i<4;i++){
			if(mp[yy+py[i]][xx+px[i]] == 5){
				printf("%d\n",d+1);
				return 0;
			}
		}
		///dot
		for(int i=0;i<4;i++){
			if(mp[yy+py[i]][xx+px[i]] == 1 && chk[yy+py[i]][xx+px[i]][a][b][c] == false){
				chk[yy+py[i]][xx+px[i]][a][b][c] = true;
				q.push(graph(yy+py[i],xx+px[i],d+1,a,b,c));
			}
		}
		///small letter j (-2)
		for(int i=0;i<4;i++){
			if(mp[yy+py[i]][xx+px[i]] == -2 && chk[yy+py[i]][xx+px[i]][true][b][c] == false){
				chk[yy+py[i]][xx+px[i]][true][b][c] = true;
				q.push(graph(yy+py[i],xx+px[i],d+1,true,b,c));
			}
		}
		///small letter b (-3)
		for(int i=0;i<4;i++){
			if(mp[yy+py[i]][xx+px[i]] == -3 && chk[yy+py[i]][xx+px[i]][a][true][c] == false){
				chk[yy+py[i]][xx+px[i]][a][true][c] = true;
				q.push(graph(yy+py[i],xx+px[i],d+1,a,true,c));
			}
		}
		///small letter p (-4)
		for(int i=0;i<4;i++){
			if(mp[yy+py[i]][xx+px[i]] == -4 && chk[yy+py[i]][xx+px[i]][a][b][true] == false){
				chk[yy+py[i]][xx+px[i]][a][b][true] = true;
				q.push(graph(yy+py[i],xx+px[i],d+1,a,b,true));
			}
		}

		///upper letter J (2)
		for(int i=0;i<4;i++){
			if(mp[yy+py[i]][xx+px[i]] == 2 && chk[yy+py[i]][xx+px[i]][a][b][c] == false && a == true){
				chk[yy+py[i]][xx+px[i]][a][b][c] = true;
				q.push(graph(yy+py[i],xx+px[i],d+1,a,b,c));
			}
		}

		///upper letter B (3)
		for(int i=0;i<4;i++){
			if(mp[yy+py[i]][xx+px[i]] == 3 && chk[yy+py[i]][xx+px[i]][a][b][c] == false && b == true){
				chk[yy+py[i]][xx+px[i]][a][b][c] = true;
				q.push(graph(yy+py[i],xx+px[i],d+1,a,b,c));
			}
		}

		///upper letter P (4)
		for(int i=0;i<4;i++){
			if(mp[yy+py[i]][xx+px[i]] == 4 && chk[yy+py[i]][xx+px[i]][a][b][c] == false && c == true){
				chk[yy+py[i]][xx+px[i]][a][b][c] = true;
				q.push(graph(yy+py[i],xx+px[i],d+1,a,b,c));
			}
		}
	}
	printf("-1\n");
	return 0;
}