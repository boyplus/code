#include <cstdio>
#include <cstring>
using namespace std;
char str[200005];
int main(){
	int ans = 0,n;
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=n-1;i>=0;i--){
		// printf("in %d\n",i);
		if(str[i] == '0'){
			if(i == n-1){
				ans++;
			} else{
				ans+=2;
			}
			while(i-1>=0 && str[i-1] == '0'){
				i--;
			}
		}
		
	}
	printf("%d\n",ans);
	return 0;
}