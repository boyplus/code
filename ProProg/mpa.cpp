#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
vector< pair<int,int> > vec[220];
int main(){
	int n,m,tempM,u,v;
	scanf("%d %d",&m,&n);
	tempM = m * n;
	for(int i=0;i<tempM;i++){
		char q;
		scanf("%d %c %d",&u,&q,&v);
		/// 1 -> U , 3 -> N 
		/// 2 -> L , 4 -> R
		/// 1 U 5 -> 1 on 5
		if(q == 'U'){
			vec[u].push_back(make_pair(v,1));
			vec[v].push_back(make_pair(u,3));
		}
		else{
			vec[u].push_back(make_pair(v,2));
			vec[v].push_back(make_pair(u,4));
		}
	}
	return 0;
}