#include <cstdio>
#include <queue>
using namespace std;
bool chk[2020][2020] = {false};
int m,n;
void Trav(int y,int x){
	chk[y][x] = false;
	
	
}
int main(){
	int count=0;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		char str;
		for(int j=1;j<=n;j++){
			scanf(" %c",&str);
			if(str == '1'){
				chk[i][j] = true;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(chk[i][j]){
				count++;
				///BFS
				queue<int> yy,xx;
				yy.push(i);
				xx.push(j);
				while(!yy.empty()){
					int y = yy.front();
					int x = xx.front();
					chk[y][x] = false;
					if(chk[y][x-1]){
						chk[y][x-1] = false;
						yy.push(y);
						xx.push(x-1);
					}
					if(chk[y][x+1]){
						chk[y][x+1] = false;
						yy.push(y);
						xx.push(x+1);
					}
					if(chk[y-1][x]){
						chk[y-1][x] = false;
						yy.push(y-1);
						xx.push(x);
					}
					if(chk[y+1][x]){
						chk[y+1][x] = false;
						yy.push(y+1);
						xx.push(x);
					}
					if(chk[y-1][x-1]){
						chk[y-1][x-1] = false;
						yy.push(y-1);
						xx.push(x-1);
					}
					if(chk[y+1][x-1]){
						chk[y+1][x-1] = false;
						yy.push(y+1);
						xx.push(x-1);
					}
					if(chk[y+1][x+1]){
						chk[y+1][x+1] = false;
						yy.push(y+1);
						xx.push(x+1);
					}
					if(chk[y-1][x+1]){
						chk[y-1][x+1] = false;
						yy.push(y-1);
						xx.push(x+1);
					}
					yy.pop();
					xx.pop();
				}
			}
		}
	}
	printf("%d\n",count);
	return 0;
}