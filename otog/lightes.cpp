#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
class Item{
public:
	int w,v;
	Item(int w,int v){
		this->w = w;
		this->v = v;
	}
};
struct cmp{
	bool operator()(const Item& left,const Item& right){
		return left.w > right.w;
	}
};
priority_queue<Item,vector<Item>,cmp > q;
int main(){
	int n,m,w,v;
	scanf("%d %d",&n,&m);
	char cmd;
	int N = n+m;
	while(N--){
		scanf(" %c",&cmd);
		if(cmd == 'T'){
			scanf("%d %d",&w,&v);
			q.push(Item(w,v));
		} else{
			if(!q.empty()){
				int v = q.top().v;
				q.pop();
				printf("%d\n",v);
			} else{
				printf("0\n");
			}
		}
	}

    return 0;
}