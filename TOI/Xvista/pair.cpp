#include <cstdio>
int count[1000001],num[100000];
int main(){
	int n,m,want;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		count[num[i]]++;
	}
	while(m--){
		bool chk = false;
		scanf("%d",&want);
		for(int i=0;i<n;i++){
			int diff = want - num[i];
			if(diff >=0){
				if(diff == num[i]){
					if(count[diff] >= 2){
						printf("YES\n");
						chk = true;
						break;
					}
				}
				else{
					if(count[diff] >= 1){
						printf("YES\n");
						chk = true;
						break;
					}
				}
			}
		}
		if(chk == false){
			printf("NO\n");
		}
	}
	return 0;
}