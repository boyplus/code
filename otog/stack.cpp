#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
stack<int> st;
int main(){
	int tt,num;
	char cmd[10];
	scanf("%d",&tt);
	while(tt--){
		scanf("%s",cmd);
		if(strcmp(cmd,"push") == 0){
			scanf("%d",&num);
			st.push(num);
		} else{
			if(!st.empty()){
				printf("%d\n",st.top());
				st.pop();
			} else{
				printf("null\n");
			}
		}
	}	 
    return 0;
}