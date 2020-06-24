#include <cstdio>
#include <string.h>
bool chk[200];
int main(){
	char str[2000];
	gets(str);
	int length = strlen(str),count=0;
	for(int i=0;i<length;i++){
		if(str[i] >= 'a' && str[i] <= 'z'){
			chk[str[i]] = true;
		}
	}
	for(int i='a';i<='z';i++){
		if(chk[i]){
			count++;
		}
	}
	printf("%d\n",count);
	return 0;
}