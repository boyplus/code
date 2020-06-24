#include <cstdio>
#include <string.h>
char def[3][20] = {"qwertyuiop","asdfghjkl;","zxcvbnm,./"};
int main(){
	char direc;
	char str[101];
	scanf(" %c",&direc);
	scanf(" %s",str);
	int length = strlen(str);
	for(int i=0;i<length;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<10;k++){
				if(str[i] == def[j][k]){
					if(direc == 'R'){
						printf("%c",def[j][k-1]);
					}
					else{
						printf("%c",def[j][k+1]);
					}
				}
			}
		}
	}
	printf("\n");
	return 0;
}