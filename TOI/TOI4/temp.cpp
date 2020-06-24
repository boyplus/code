#include <cstdio>
int num[25][25],max = -6,m;
void Trav(int y,int x,int c){
	if(c > max){
		max = c;
	}
	if(num[y][x-1] != 100 && num[y][x-1] > c && x-1>=1){
		Trav(y,x-1,num[y][x-1]);
	}
	if(num[y][x+1] != 100 && num[y][x+1] > c && x+1 <=m){
		Trav(y,x+1,num[y][x+1]);
	}
	if(num[y-1][x] != 100 && num[y-1][x] > c && y-1>=1){
		Trav(y-1,x,num[y-1][x]);
	}
	if(num[y+1][x] != 100 && num[y+1][x] > c && y+1 <= m){
		Trav(y+1,x,num[y+1][x]);
	}
}
int main(){
	int x,y;
	scanf("%d",&m);
	scanf("%d %d",&x,&y);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&num[i][j]);
		}
	}
	Trav(y,x,num[y][x]);
	printf("%d\n",max);
	return 0;
}