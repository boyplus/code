#include <cstdio>
char str[50010][200] = {""};
int row[50010],start[50010],num[50010];
int main(){
	int n,max=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&row[i],&start[i],&num[i]);
		if(row[i] > max){
			max = row[i];
		}
	}
	for(int i=0;i<max;i++){
		for(int j=0;j<70;j++){
			str[i][j] = 'o';
		}
	}
	for(int i=0;i<n;i++){
		row[i]--;
		start[i]--;
		int end = start[i] + num[i];
		for(int j=start[i];j<end;j++){
			str[row[i]][j] = 'x';
		}
	}
	for(int i=0;i<max;i++){
		str[i][70] = '\0';
		printf("%s\n",str[i]);
	}
	return 0;
}