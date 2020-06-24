#include <cstdio>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
vector<int> saveY,saveX;
bool chk[100][100] = {false};
int m,n;
char str[100][100] = {""};
bool check(int,int,int);
void Trav(int,int);
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%s",str[i]);
	}
	///find max of school
	int max = 0,count=0,min = INT_MAX;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			int w=1;
			while(check(i,j,w) == true && w<=m && w<=n){
				if(w>max){
					saveY.clear();
					saveX.clear();
					saveY.push_back(i);
					saveX.push_back(j);
					max = w;

				}
				else if(w == max){
					saveY.push_back(i);
					saveX.push_back(j);
				}
				w++;
			}

		}
	}
	///find pool
	for(int i=0;i<saveY.size();i++){
		for(int j=0;j<m;j++){
			fill(chk[j],chk[j]+n,false);
		}
		int count=0;
		for(int j=saveY[i];j<saveY[i]+max;j++){
			for(int k=saveX[i];k<saveX[i]+max;k++){
				if(str[j][k] == 'P' && chk[j][k] == false){
					count++;
					Trav(j,k);
				}
			}
		}
		if(count < min){
			min = count;
		}
	}
	if(max == 0){
		min = 0;
	}
	printf("%d %d\n",max*max,min);
	return 0;
}
void Trav(int y,int x){
	chk[y][x] = true;
	if(str[y][x-1] == 'P' && chk[y][x-1] == false && x-1>=0){
		Trav(y,x-1);
	}
	if(str[y][x+1] == 'P' && chk[y][x+1] == false && x+1 <= n){
		Trav(y,x+1);
	}
	if(str[y-1][x] == 'P' && chk[y-1][x] == false && y-1 >=0){
		Trav(y-1,x);
	}
	if(str[y+1][x] == 'P' && chk[y+1][x] == false && y+1<=m){
		Trav(y+1,x);
	}
}
bool check(int y,int x,int w){
	int down = y+w;
	int right = x+w;
	for(int i=y;i<down;i++){
		for(int j=x;j<right;j++){
			if(str[i][j] == 'T' || i>=m || j>=n){
				return false;
			}
		}
	}
	return true;
}