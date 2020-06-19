#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
queue<int> q;
int main(){
	int tt,num;
	char cmd[10];
	scanf("%d",&tt);
	while(tt--){
		scanf("%s",cmd);
		if(strcmp(cmd,"push") == 0){
			scanf("%d",&num);
			q.push(num);
		} else{
			if(!q.empty()){
				printf("%d\n",q.front());
				q.pop();
			} else{
				printf("null\n");
			}
		}
	}	 
    return 0;
}