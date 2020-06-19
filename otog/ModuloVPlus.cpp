#include <cstdio>
#include <set>
using namespace std;
set<int> s;
int main(){
	int n,k,num;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		num%=k;
		s.insert(num);
	}
	printf("%d\n",(int)s.size());
	for(auto x:s){
		printf("%d\n",x);
	}
    return 0;
}