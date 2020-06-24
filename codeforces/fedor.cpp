#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
vector<bool> bi[1001];
int main(){
	int n,m,k,ans=0,temp;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<=m;i++){
		scanf("%d",&temp);
		stack<int> st;
		while(temp != 0){
			st.push(temp%2);
			temp/=2;
		}
		int tempSize = st.size();
		while(tempSize != n){
			bi[i].push_back(0);
			tempSize++;
		}
		for(int j=0;j<n && st.empty() == false;j++){
			bi[i].push_back(st.top());
			st.pop();
		}
	}
	for(int i=0;i<m;i++){
		int count = 0;
		bool chk = true;
		for(int j=0;j<bi[i].size();j++){
			if(bi[i][j] != bi[m][j]){
				count++;
				if(count > k){
					chk = false;
					break;
				}
			}
		}
		if(chk == true && count <= k){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}