#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class bom{
public:
	int x;
	int y;
	bom(int xx,int yy){
		x = xx;
		y = yy;
	}
};
vector<bom> vec;
bool cmp(const bom& left,const bom& right){
	if(left.x > right.x){
		return left.x > right.x;
	}
	if(left.x == right.x){
		return left.y < right.y;
	}
	return 0;
}
bool chk[2000000];
int main(){
	int n,x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&x,&y);
		vec.push_back(bom(x,y));
	}
	sort(vec.begin(),vec.end(),cmp);
	int maxY = -1;
	for(int i=0;i<n;i++){
		if(vec[i].y >= maxY){
			maxY = vec[i].y;
			chk[i] = true;
		}
	}
	for(int i=0;i<n;i++){
		if(chk[i] == true){
			printf("%d %d\n",vec[i].x,vec[i].y);
		}
	}
	return 0;
}