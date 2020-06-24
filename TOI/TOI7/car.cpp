#include <cstdio>
int m,n,t,temp;
bool chk[102][42];
int ans[102];
void Trav(int row,int col){
	if(row == t){
		for(int i=0;i<row;i++){
			printf("%d\n",ans[i]);
		}
	}
	if(chk[row+1][col-1] == 1){
		ans[row] = 1;
		Trav(row+1,col-1);
	}
	if(chk[row+1][col+1] == 1){
		ans[row] = 2;
		Trav(row+1,col+1);
	}
	if(chk[row+1][col] == 1){
		ans[row] = 3;
		Trav(row+1,col);
	}
}
int main(){
	scanf("%d %d %d",&m,&n,&t);
	for(int i=1;i<=t;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&temp);
			chk[i][j] = !temp;
		}
	}
	Trav(0,n);
	return 0;
}