#include <cstdio>
int fre[200];
int main(){
	int n,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		fre[temp]++;
	}
	for(int i=0;i<=100;i++){
		if(fre[i] == 1){
			printf("%d\n",i);
			return 0;
		}
	}
	return 0;
}