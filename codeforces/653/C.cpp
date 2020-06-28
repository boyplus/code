#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char s[100] = "";
		int len;
		scanf("%d",&len);
		scanf("%s",s);
		for(int i=0;i<len;i++){
			if(s[i] == '('){
				for(int j=i+1;j<len;j++){
					if(s[j] == ')'){
						s[i] = '-';
						s[j] = '-';
						break;
					}
				}
			}
		}
		int cnt = 0;
		for(int i=0;i<len;i++){
			if(s[i] != '-'){
				cnt++;
			}
		}
		printf("%d\n",cnt/2);
	}
	
	return 0;
}