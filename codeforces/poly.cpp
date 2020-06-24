#include <cstdio>
#include <string.h>
char def[5][20] = {"Tetrahedron","Cube","Octahedron","Dodecahedron","Icosahedron"};
int face[5] = {4,6,8,12,20};
int main(){
	char str[20];
	int T,score=0;
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		int len = strlen(str);
		for(int i=0;i<5;i++){
			if(strcmp(str,def[i]) == 0){
				score+=face[i];
				break;
			}
		}
	}
	printf("%d\n",score);
	return 0;
}