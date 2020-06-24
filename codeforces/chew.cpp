#include <cstdio>
#include <string.h>
int main(){
	char str[20];
	scanf("%s",str);
	int length = strlen(str);
	for(int i=0;i<length;i++){
		int d = str[i]-48,temp = str[i]-48;
		if(9 - d < temp && 9-d >=0){
			if(9-d == 0){
				if(i!=0){
					str[i] = (9-d)+48;
				}
			}
			else{
				str[i] = (9-d)+48;
			}
			
		}
	}
	printf("%s\n",str);
	return 0;
}