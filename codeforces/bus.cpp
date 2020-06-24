#include <cstdio>
char str[1000][10];
int main(){
	int n;
	bool have = false;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",str[i]);
	}
	for(int i=0;i<n;i++){
		if(str[i][0] == 'O' && str[i][1] == 'O'){
			str[i][0] = '+';
			str[i][1] = '+';
			have = true;
			break;
		}
		else if(str[i][3] == 'O' && str[i][4] == 'O'){
			str[i][3] = '+';
			str[i][4] = '+';
			have = true;
			break;
		}
	}
	if(have){
		printf("YES\n");
		for(int i=0;i<n;i++){
			printf("%s\n",str[i]);
		}
	}
	else{
		printf("NO\n");
	}
	return 0;
}