#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector< pair<int,int> > vec[300];
vector<char> par,node;
vector<float> med;
int main(){
	float sum = 0.00;
	int n,dist;
	char u,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf(" %c  %c %d",&u,&v,&dist);
		vec[u].push_back(make_pair(v,dist));
		vec[v].push_back(make_pair(u,dist));
	}
	char nowNode = 'X',parent = '-';
	while(nowNode != 'Y'){
		bool find = false;
		vector<int> ans;
		int vecSize = vec[nowNode].size();
		int nextNode = 0;
		for(int i=0;i<vecSize;i++){
			int node = vec[nowNode].at(i).first;
			int distance = vec[nowNode].at(i).second;
			if(node != parent){
				find = true;
				nextNode = node;
				ans.push_back(distance);
			}
		}
		if(find == false){
			printf("broken\n");
			return 0;
		}
		sort(ans.begin(),ans.end());
		int ansSize = ans.size();
		float median = 0;
		if(ansSize%2){
			median = ans[ansSize/2];
		}
		else{
			median = (ans[ansSize/2]+ans[ansSize/2-1])/2.00;
		}
		sum+=median;
		parent = nowNode;
		nowNode = nextNode;
		par.push_back(parent);
		node.push_back(nowNode);
		med.push_back(median);
	}
	int medSize = med.size();
	for(int i=0;i<medSize;i++){
		printf("%c %c %.1f\n",par[i],node[i],med[i]);
	}
	printf("%.1f\n",sum);
	return 0;
}