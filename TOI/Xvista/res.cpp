#include <cstdio>
#include <algorithm>
using namespace std;
int t[1000000];
int main(){
	int n,m,now=1;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&t[i]);
	}
	sort(t,t+n);
	int tempN = n;
	while(m>0 && tempN>0){
		printf("0\n");
		m--;
		tempN--;
	}
	while(m>0){
		for(int i=0;i<n && now>=t[i] && m>0;i++){
			if(now % t[i] == 0){
				printf("%d\n",now);
				m--;
			}
		}
		now++;
	}
	return 0;
}