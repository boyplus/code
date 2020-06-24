#include <cstdio>
int main(){
	int m,n;
	char color;
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf(" %c",&color);
			if(color == 'C' || color == 'M' || color == 'Y'){
				printf("#Color\n");
				return 0;
			}
		}
	}
	printf("#Black&White\n");
	return 0;
}