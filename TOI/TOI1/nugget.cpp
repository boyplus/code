#include <cstdio>
#include <set>
using namespace std;
set<int> ans;
int main(){
	bool have = false;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				int num = (i*20)+(j*9)+(k*6);
				if(num){
					if(num > n){
						break;
					}
					have = true;
					ans.insert(num);
				}
			}
		}
	}
	if(have == false){
		printf("no\n");
	}
	set<int>::iterator it;
	for(it = ans.begin();it!=ans.end();it++){
		printf("%d\n",*it);
	}
	return 0;
}