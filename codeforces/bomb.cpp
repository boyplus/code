#include <cstdio>
#include <vector>
using namespace std;
char str[1010][1010];
int row[1010],col[1010],max_row=0,max_col=0,wantY=0,wantX=0;
class grid{
public:
	int y,x;
	grid(int y,int x){
		this->y = y;
		this->x = x;
	}
};
vector<grid> vec;
int main(){
	int m,n;	
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		scanf("%s",str[i]);
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(str[i][j] == '*'){
				row[i]++;
				col[j]++;
				if(row[i] > max_row){
					max_row = row[i];
					wantY = i;
				}
				if(col[j] > max_col){
					max_col = col[j];
					wantX = j;
				}
				vec.push_back(grid(i,j));
			}
		}
	}
	bool have = true;
	//printf("%d %d\n",wantY,wantX);
	if(max_row > max_col){
		int index = -1;
		for(int i=0;i<vec.size();i++){
			if(vec[i].y != wantY){
				index = i;
				break;
			}
		}
		
		if(index != -1){
			wantX = vec[index].x;
			for(int i=index;i<vec.size();i++){
				if(vec[i].y != wantY && vec[i].x != wantX){
					have = false;
					break;
				}
			}
		}
	}
	else{
		int index = -1;
		for(int i=0;i<vec.size();i++){
			if(vec[i].x != wantX){
				index = i;
				break;
			}
		}
		if(index != -1){
			wantY = vec[index].y;
			for(int i=index;i<vec.size();i++){
				if(vec[i].x != wantX && vec[i].y != wantY){
					have = false;
					break;
				}
			}
		}
	}
	if(have){
		printf("YES\n%d %d\n",wantY+1,wantX+1);
	}
	else{
		printf("NO\n");
	}
	return 0;
}