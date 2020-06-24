#include <cstdio>
#include <vector>
#include <limits.h>
using namespace std;
class store
{
public:
	int x,y,z,m,k,c;
	store(int x,int y,int z,int m,int k,int c){
		this->x = x;
		this->y = y;
		this->z = z;
		this->m = m;
		this->k = k;
		this->c = c;
	}
};
int N,M,x,y,z,Min = INT_MAX;
vector<store> vec;
bool visited[30];
void Trav(int x,int y,int z,int monitor,int key,int ca,int cost){
	if(monitor >= N && key >= N && ca >= N){
		if(cost < Min){
			Min = cost;
		}
	}
	else{
		for(int i=0;i<M;i++){
			if(visited[i] == false){
				visited[i] = true;
				int x1 = x - vec[i].x;
				int y1 = y - vec[i].y;
				int z1 = z - vec[i].z;
				int pay = (x1*x1)+(y1*y1)+(z1*z1);
				Trav(vec[i].x,vec[i].y,vec[i].z,monitor+vec[i].m,key+vec[i].k,ca+vec[i].c,cost+pay);
				visited[i] = false;
			}
		}
	}
}
int main(){
	int tx,ty,tz,tm,tk,tc;
	scanf("%d",&N);
	scanf("%d %d %d",&x,&y,&z);
	scanf("%d",&M);
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&tx,&ty,&tz);
		scanf("%d %d %d",&tm,&tk,&tc);
		vec.push_back(store(tx,ty,tz,tm,tk,tc));
	}
	Trav(x,y,z,0,0,0,0);
	printf("%d\n",Min);
	return 0;
}