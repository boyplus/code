#include <cstdio>
int n,m,ans[10];
bool ban[10],chk[10];
void rec(int count){
	if(count == n){
		for(int i=0;i<n;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
	else{
		for(int i=1;i<=n;i++){
			if(count == 0){
				if(ban[i] == false){
					if(chk[i] == false){
						chk[i] = true;
						ans[count] = i;
						rec(count+1);
						chk[i] = false;
					}
				}
			}
			else{
				if(chk[i] == false){
					chk[i] = true;
					ans[count] = i;
					rec(count+1);
					chk[i] = false;
				}
			}
		}
	}
}
int main(){
	int temp;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&temp);
		ban[temp] = true;
 	}
 	rec(0);
	return 0;
}