#include <cstdio>
char str[25][25] = {""};
int main(){
	int m,n,brick;
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		scanf("%s",str[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&brick);
		while(brick--){
			int index = -1;
			bool chk = false;
			while(str[index+1][i] == '.' && index+1 < m){
				index++;
				chk = true;
			}
			if(chk == true){
				str[index][i] = '#';
			}
		}
	}
	for(int i=0;i<m;i++){
		printf("%s\n",str[i]);
	}
	return 0;
}