#include <cstdio>
int main(){
	int T = 20;
	while(T--){
		int n;
		char str[300] = "";
		scanf("%d %s",&n,str);
		if(str[0] == '0'){
			if(n == 2){
				if(str[1] == '2'){
					printf("yes\n");
				}
				else{
					printf("no\n");
				}
			}
			else{
				bool chk = false;
				int c1=0,c0=0;
				for(int i=1;i<n;i++){
					if(str[i] == '2'){
						chk = true;
						break;
					}
					if(str[i] == '1'){
						c1++;
					}
					if(str[i] == '0'){
						c0++;
					}
				}
				if(chk){
					printf("yes\n");
				}
				else if(c1>0 && c0 >0){
					printf("yes\n");
				}
				else{
					printf("no\n");
				}
			}
		}
		else{
			printf("no\n");
		}
	}

	return 0;
}