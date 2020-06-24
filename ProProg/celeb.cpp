#include <cstdio>
bool arr[1001][1001];
int main(){
	int n,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&temp);
			arr[i][j] = temp;
		}
	}
	bool have = false;
	for(int i=0;i<n;i++){
		bool chk = false;
		for(int j=0;j<n;j++){
			if(arr[i][j]){
				chk = true;
			}
		}
		if(chk == false){
			bool chk2 = true;
			for(int j=0;j<n;j++){
				if(j != i){
					if(arr[j][i] == false){
						chk2 = false;
						break;
					}
				}
			}
			if(chk2){
				printf("%d\n",i+1);
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
}