#include <cstdio>
#include <string.h>
char bi[20];
int main(){
	int n,round = 1;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		bi[i] = '1';
	}
	for(int i=0;i<n;i++){
		round*=2;
	}
	for(int i=0;i<round;i++){
		///binary counter
		int j;
		for(j=n-1;j>=0 && bi[j] == '1';j--){
			bi[j] = '0';
		}
		if(j>=0){
			bi[j] = '1';
		}
		char temp[20];
		strcpy(temp,bi);
		for(int j=n-1;j>=0;j--){
			if(bi[j] == '0'){
				temp[j] = '1';
				printf("%s %s\n",bi,temp);
				temp[j] = '0';
			}
		}
	}
	return 0;
}