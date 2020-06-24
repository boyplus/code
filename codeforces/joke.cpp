#include <cstdio>
#include <string.h>
int fre1[300],fre2[300];
int main(){
	char str1[200],str2[200],str3[300];
	scanf("%s %s %s",str1,str2,str3);
	int l1 = strlen(str1),l2 = strlen(str2),l3 = strlen(str3);
	for(int i=0;i<l1;i++){
		fre1[str1[i]]++;
	}
	for(int i=0;i<l2;i++){
		fre1[str2[i]]++;
	}
	for(int i=0;i<l3;i++){
		fre2[str3[i]]++;
	}
	for(int i='A';i<='Z';i++){
		if(fre1[i] != fre2[i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}