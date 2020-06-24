#include <cstdio>
int chk[10][10];
int main(){
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			scanf("%d",&chk[i][j]);
		}
	}
	for(int i=1;i<=4;i++){
		if(chk[i][4] == 1){
			if(i == 1){
				if(chk[1][1]||chk[1][2]||chk[1][3]||chk[2][1]||chk[3][2]||chk[4][3]){
					printf("YES\n");
					return 0;
				}
			}
			else if(i == 2){
				if(chk[2][1]||chk[2][2]||chk[2][3]||chk[1][3]||chk[3][1]||chk[4][2]){
					printf("YES\n");
					return 0;
				}
			}
			else if(i == 3){
				if(chk[3][1]||chk[3][2]||chk[3][3]||chk[1][2]||chk[2][3]||chk[4][1]){
					printf("YES\n");
					return 0;
				}
			}
			else if(i == 4){
				if(chk[4][1]||chk[4][2]||chk[4][3]||chk[1][1]||chk[2][2]||chk[3][3]){
					printf("YES\n");
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}