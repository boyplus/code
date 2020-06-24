#include <cstdio>
int n;
char str[100][10] = {""};
void rec(int row){
	if(row == n){
		for(int i=0;i<n;i++){
			if(str[i][0] == '|' && str[i+1][0] == '|'){
				printf("||");
				i++;
			}
			else if(str[i][0] == '|'){
				printf("||");
				i++;
			}
			else{
				printf("--");
			}
			printf("\n");
		}
		printf("E\n");
	}
	else{
		str[row][0] = '-';
		str[row][1] = '-';
		rec(row+1);
		if(row+1 < n){
			str[row][0] = '|';
			str[row][1] = '|';
			rec(row+2);
		}
	}
}
int main(){
	scanf("%d",&n);
	rec(0);
	return 0;
}