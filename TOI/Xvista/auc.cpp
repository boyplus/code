#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class auc{
public:
	int user;
	int price;
	auc(int user,int price){
		this->user = user;
		this->price = price;
	}
};
int piece[1000001];
vector<auc> vec[1000001];
vector<int> win[1000001];
bool cmp(const auc& left,const auc& right){
	if(left.price > right.price){
		return left.price > right.price;
	}
	if(left.price == right.price){
		return left.user > right.user;
	}
	return 0;
}
int main(){
	int n,m,a,U,I,V;
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1;i<=n;i++){
		scanf("%d",&piece[i]);
	}
	while(a--){
		char cmd;
		scanf(" %c",&cmd);
		if(cmd == 'B'){
			scanf("%d %d %d",&U,&I,&V);
			///search to find old price
			bool chk = false;
			int vecSize = vec[I].size();
			for(int i=0;i<vecSize;i++){
				if(vec[I][i].user == U){
					vec[I][i].price = V;
					chk = true;
					break;
				}
			}
			if(chk == false){
				vec[I].push_back(auc(U,V));
			}
		}
		else if(cmd == 'W'){
			scanf("%d %d",&U,&I);
			int vecSize = vec[I].size();
			for(int i=0;i<vecSize;i++){
				if(vec[I][i].user == U){
					vec[I].erase(vec[I].begin()+i);
					break;
				}
			}

		}
	}
	///sort the vector
	for(int i=1;i<=n;i++){
		sort(vec[i].begin(),vec[i].end(),cmp);
	}
	///calculate who win
	for(int i=1;i<=n;i++){
		int vecSize = vec[i].size();
		for(int j=0;j<piece[i] && j<vecSize;j++){
			win[vec[i][j].user].push_back(i);
		}
	}
	///print who win
	for(int i=1;i<=m;i++){
		if(win[i].empty()){
			printf("NONE\n");
		}
		else{
			int winSize = win[i].size();
			for(int j=0;j<winSize;j++){
				printf("%d ",win[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}