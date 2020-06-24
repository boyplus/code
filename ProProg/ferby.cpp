#include <cstdio>
#include <string.h>
int main(){
	char str[1000000] = "";
	char def[7][20] = {"boh","boo","bah","dah","dee","doh","doo"};
	for(int i=1;i<=100;i++){
		gets(str);
		bool chk = false;
		for(int j=0;j<7;j++){
			if(strcmp(str,def[i]) == 0){
				chk = true;
			}
		}
		if(chk == false){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}