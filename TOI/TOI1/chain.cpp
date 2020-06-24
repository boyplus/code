#include <cstdio>
#include <string.h>
int main(){
	int length,n;
	char temp[1001],str[1001];
	scanf("%d %d",&length,&n);
	scanf("%s",temp);
	for(int i=1;i<n;i++){
		scanf("%s",str);
		int count=0;
		for(int j=0;j<length;j++){
			if(temp[j] != str[j]){
				count++;
				if(count > 2){
					printf("%s\n",temp);
					return 0;
				}
			}
		}
		strcpy(temp,str);
	}
	printf("%s\n",temp);
	return 0;
}