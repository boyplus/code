#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int tc = 5;
	while(tc--){
		vector<int> tree1[100001],tree2[100001];
		int n,u,v;
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			tree1[u].push_back(v);
			tree1[v].push_back(u);
		}
		for(int i=1;i<n;i++){
			scanf("%d %d",&u,&v);
			tree2[u].push_back(v);
			tree2[v].push_back(u);
		}
		bool chk = true;
		for(int i=1;i<=n;i++){
			int sizeTree1 = tree1[i].size();
			int sizeTree2 = tree2[i].size();
			if(sizeTree1 == sizeTree2){
				sort(tree1[i].begin(),tree1[i].end());
				sort(tree2[i].begin(),tree2[i].end());
				for(int j=0;j<sizeTree1;j++){
					if(tree1[i].at(j) != tree2[i].at(j)){
						printf("N");
						chk = false;
						break;
					}
				}
			}
			else{
				printf("N");
				chk = false;
				break;
			}
			if(chk == false){
				break;
			}
		}
		if(chk == true){
			printf("Y");
		}
	}

	return 0;
}