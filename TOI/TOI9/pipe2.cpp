#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int num[310][310],border=0,m,n,cc=0;
int DFS(int,int,int,int,int);
void print();
vector<int> ans;
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
			if(i == 1 && (num[i][j] == 11 || num[i][j] == 12 || num[i][j] == 21 || num[i][j] == 31)){
				cc++;
				//printf("in %d %d\n",i,j);
				int temp = DFS(i,j,0,0,0);
				//cc+=temp;
			}
			else if(i == m &&(num[i][j] == 13 || num[i][j] == 14 || num[i][j] == 21 || num[i][j] == 31)){
				cc++;
				int temp = DFS(i,j,0,0,0);
				
				//cc+=temp;
			}
			else if(j == 1 && (num[i][j] == 11 || num[i][j] == 13 || num[i][j] == 22 || num[i][j] == 31)){
				cc++;
				int temp = DFS(i,j,0,0,0);
				//cc+=temp;
			}
			else if(j == n && (num[i][j] == 12 || num[i][j] == 14 || num[i][j] == 22 || num[i][j] == 31)){
				cc++;
				int temp = DFS(i,j,0,0,0);
				//cc+=temp;
			}
		}
	}
	printf("%d\n",cc);
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]+1);
	}
	for(int i=ans.size();i<cc;i++){
		printf("1 ");
	}
	return 0;
}
int DFS(int y,int x,int py,int px,int c){
	int now = num[y][x];
	if(num[y][x] == 31){
		if(py < y || py > y){
			num[y][x] = 22;
		}
		else{
			num[y][x] = 21;
		}
	}
	else{
		num[y][x] = 0;
	}
	if(c!=0){
		if(now == 11){
			if(y == 1 || x == 1){
				ans.push_back(c);
				return 1;
			}
		}
		else if(now == 12){
			if(y == 1 || x == n){
				ans.push_back(c);
				return 1;
			}
		}
		else if(now == 13){
			if(x == 1 || y == m){
				ans.push_back(c);
				return 1;
			}
		}
		else if(now == 14){
			if(x == n || y == m){
				ans.push_back(c);
				return 1;
			}
		}
		else if(now == 21){
			if(y == 1 || y == m){
				ans.push_back(c);
				return 1;
			}
		}
		else if(now == 22){
			if(x == 1 || x == n){
				ans.push_back(c);
				return 1;
			}
		}
		else if(now == 31){
			if(x==1 || x == n){
				ans.push_back(c);
				return 1;
			}
			if(y==1 || y==m){
				ans.push_back(c);
				return 1;
			}
		}
	}
	if(now == 11){
		//in left
		int arr[4] = {12,14,22,31};
		for(int i=0;i<4;i++){
			if(num[y][x-1] == arr[i]){
				DFS(y,x-1,y,x,c+1);
			}
		}
		///in top
		int arr2[4] = {13,14,21,31};
		for(int i=0;i<4;i++){
			if(num[y-1][x] == arr2[i]){
				DFS(y-1,x,y,x,c+1);
			}
		}
	}
	else if(now == 12){
		///in right
		int arr[4] = {11,13,22,31};
		for(int i=0;i<4;i++){
			if(num[y][x+1] == arr[i]){
				DFS(y,x+1,y,x,c+1);
			}
		}
		///in top
		int arr2[4] = {13,14,21,31};
		for(int i=0;i<4;i++){
			if(num[y-1][x] == arr2[i]){
				DFS(y,x+1,y,x,c+1);
			}
		}
	}
	else if(now == 13){
		///in left
		int arr[4] = {12,14,22,31};
		for(int i=0;i<4;i++){
			if(num[y][x-1] == arr[i]){
				DFS(y,x-1,y,x,c+1);
			}
		}
		///in down
		int arr2[4] = {11,12,21,31};
		for(int i=0;i<4;i++){
			if(num[y+1][x] == arr2[i]){
				DFS(y+1,x,y,x,c+1);
			}
		}
	}
	else if(now == 14){
		//in right
		int arr[4] = {11,13,22,31};
		for(int i=0;i<4;i++){
			if(num[y][x+1] == arr[i]){
				DFS(y,x+1,y,x,c+1);
			}
		}
			///in down
		int arr2[4] = {11,12,21,31};
		for(int i=0;i<4;i++){
			if(num[y+1][x] == arr2[i]){
				DFS(y+1,x,y,x,c+1);
			}
		}
	}
	else if(now == 21){
		//in top
		int arr[4] = {13,14,31,21};
		for(int i=0;i<4;i++){
			if(num[y-1][x] == arr[i]){
				DFS(y-1,x,y,x,c+1);
			}
		}
			//in down
		int arr2[4] = {11,12,31,21};
		for(int i=0;i<4;i++){
			if(num[y+1][x] == arr2[i]){
				DFS(y+1,x,y,x,c+1);
			}
		}
	}
	else if(now == 22){
		//in left
		int arr[4] = {12,14,31,22};
		for(int i=0;i<4;i++){
			if(num[y][x-1] == arr[i]){
				DFS(y,x-1,y,x,c+1);
			}
		}
		//in right
		int arr2[4] = {11,13,31,22};
		for(int i=0;i<4;i++){
			if(num[y][x+1] == arr2[i]){
				DFS(y,x+1,y,x,c+1);
			}
		}
	}
	else if(now == 31){
		//in left
		if(num[y][x] == 21){
			//in left
			int arr[] = {12,14,22,31};
			for(int i=0;i<4;i++){
				if(num[y][x-1] == arr[i]){
					DFS(y,x-1,y,x,c+1);
				}
			}
			//in right
			int arr2[] = {11,13,22,31};
			for(int i=0;i<4;i++){
				if(num[y][x+1] == arr2[i]){
					DFS(y,x+1,y,x,c+1);
				}
			}
		}
		else{
			//in top
			int arr3[] = {13,14,21,31};
			for(int i=0;i<4;i++){
				if(num[y-1][x] == arr3[i]){
					DFS(y-1,x,y,x,c+1);
				}
			}
			//in down
			int arr4[] = {11,12,21,31};
			for(int i=0;i<4;i++){
				if(num[y+1][x] == arr4[i]){
					DFS(y+1,x,y,x,c+1);
				}
			}
		}
		
	}
	return 0;
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