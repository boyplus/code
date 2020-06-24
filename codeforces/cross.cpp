#include <cstdio>
#include <vector>
using namespace std;
char str[102];
vector<int> ans;
int main(){
	int n,count=0;
	scanf("%d %s",&n,str);
	for(int i=0;i<=n;i++){
		if(str[i] == 'B'){
			count++;
		}
		else{
			if(count != 0){
				ans.push_back(count);
			}
			count = 0;
		}
	}
	printf("%d\n",(int)ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	return 0;
}