#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int num[310][310],border=0,m,n;
void BFS(int,int);
void print();
int main(){
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&num[i][j]);
		}
	}
	//find pipe
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if((i == 1 || i == m || j==1 || j==n) && num[i][j]){
				///start find pipe
				BFS(i,j);
				print();
				getchar();
			}
		}
	}
	printf("border = %d\n",border);
	return 0;
}
void BFS(int sy,int sx){
	printf("in %d %d\n",sy,sx);
	queue<int> y,x;
	y.push(sy);
	x.push(sx);
	while(!y.empty()){
		int yy = y.front();
		int xx = x.front();
		if(num[yy][xx] == 11){
			if(yy == 1){
				border++;
			}
			if(xx == 1){
				border++;
			}
			///in left
			int arr[4] = {12,14,22,31};
			for(int i=0;i<4;i++){
				if(num[yy][xx-1] == arr[i]){
					y.push(yy);
					x.push(xx-1);
				}
			}
			///in top
			int arr2[4] = {13,14,21,31};
			for(int i=0;i<4;i++){
				if(num[yy-1][xx] == arr2[i]){
					y.push(yy-1);
					x.push(xx);
				}
			}
		}
		else if(num[yy][xx] == 12){
			if(yy == 1){
				border++;
			}
			if(xx == n){
				border++;
			}
			///in right
			int arr[4] = {11,13,22,31};
			for(int i=0;i<4;i++){
				if(num[yy][xx+1] == arr[i]){
					y.push(yy);
					x.push(xx+1);
				}
			}
			///in top
			int arr2[4] = {13,14,21,31};
			for(int i=0;i<4;i++){
				if(num[yy-1][xx] == arr2[i]){
					y.push(yy-1);
					x.push(xx);
				}
			}
		}
		else if(num[yy][xx] == 13){
			if(xx == 1){
				border++;
			}
			if(yy == m){
				border++;
			}
			///in left
			int arr[4] = {12,14,22,31};
			for(int i=0;i<4;i++){
				if(num[yy][xx-1] == arr[i]){
					y.push(yy);
					x.push(xx-1);
				}
			}
			///in down
			int arr2[4] = {11,12,21,31};
			for(int i=0;i<4;i++){
				if(num[yy+1][xx] == arr2[i]){
					y.push(yy+1);
					x.push(xx);
				}
			}
		}
		else if(num[yy][xx] == 14){
			if(xx == n){
				border++;
			}
			if(yy == m){
				border++;
			}
			//in right
			int arr[4] = {11,13,22,31};
			for(int i=0;i<4;i++){
				if(num[yy][xx+1] == arr[i]){
					y.push(yy);
					x.push(xx+1);
				}
			}
			///in down
			int arr2[4] = {11,12,21,31};
			for(int i=0;i<4;i++){
				if(num[yy+1][xx] == arr2[i]){
					y.push(yy+1);
					x.push(xx);
				}
			}
		}
		else if(num[yy][xx] == 21){
			if(yy == 1 || yy == m){
				border++;
			}
			//in top
			int arr[3] = {13,14,31};
			for(int i=0;i<3;i++){
				if(num[yy-1][xx] == arr[i]){
					y.push(yy-1);
					x.push(xx);
				}
			}
			//in down
			int arr2[3] = {11,12,31};
			for(int i=0;i<3;i++){
				if(num[yy+1][xx] == arr2[i]){
					y.push(yy+1);
					x.push(xx);
				}
			}
		}
		else if(num[yy][xx] == 22){
			if(xx == 1 || xx == n){
				border++;
			}
			//in left
			int arr[3] = {12,14,31};
			for(int i=0;i<3;i++){
				if(num[yy][xx-1] == arr[i]){
					y.push(yy);
					x.push(xx-1);
				}
			}
			//in right
			int arr2[3] = {11,13,31};
			for(int i=0;i<3;i++){
				if(num[yy][xx+1] == arr2[i]){
					y.push(yy);
					x.push(xx+1);
				}
			}
		}
		else if(num[yy][xx] == 31){
			if(yy == 1 || yy == m){
				border++;
			}
			if(xx == 1 || xx == n){
				border++;
			}
			//in left
			int arr[] = {12,14,22,31};
			for(int i=0;i<4;i++){
				if(num[yy][xx-1] == arr[i]){
					y.push(yy);
					x.push(xx-1);
				}
			}
			//in right
			int arr2[] = {11,13,22,31};
			for(int i=0;i<4;i++){
				if(num[yy][xx+1] == arr2[i]){
					y.push(yy);
					x.push(xx+1);
				}
			}
			//in top
			int arr3[] = {13,14,21,31};
			for(int i=0;i<4;i++){
				if(num[yy-1][xx] == arr3[i]){
					y.push(yy-1);
					x.push(xx);
				}
			}
			//in down
			int arr4[] = {11,12,21,31};
			for(int i=0;i<4;i++){
				if(num[yy+1][xx] == arr4[i]){
					y.push(yy+1);
					x.push(xx);
				}
			}
		}
		y.pop();
		x.pop();
		num[yy][xx] = 0;
	}
}
void print(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",num[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}