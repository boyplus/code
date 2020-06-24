#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a,b;
int ab(int a){
	return a < 0 ? -a : a;
}
bool mark[101] = {false};
int main(){
	int n,m,num,ans=0,start;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		a.push_back(num);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&num);
		b.push_back(num);
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(ab(a[i] - b[j]) <= 1){
				if(mark[j] == false){
					ans++;
					mark[j] = true;
					start = j+1;
					break;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}