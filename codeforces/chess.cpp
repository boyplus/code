#include <cstdio>
char str[10][10],def[10] = "qrbnp";
int main(){
	int score[300] = {0},arr[5] = {9,5,3,3,1};
	int score_white=0,score_black=0;
	for(int i=0;i<5;i++){
		score[def[i]] = arr[i];
		score[def[i]-32] = arr[i];
	}
	for(int i=0;i<8;i++){
		scanf("%s",str[i]);
	}
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(str[i][j] == '.' || str[i][j] == 'k' || str[i][j] == 'K'){
				continue;
			}
			if(str[i][j] >= 'a'){
				score_black+=score[str[i][j]];
			}
			else{
				score_white+=score[str[i][j]];
			}
		}
	}
	if(score_white > score_black){
		printf("White\n");
	}
	else if(score_black > score_white){
		printf("Black\n");
	}
	else{
		printf("Draw\n");
	}
	return 0;
}