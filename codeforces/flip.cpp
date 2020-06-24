#include <cstdio>
int arr[110],temp[200],max=0;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		temp[i] = arr[i];
	}
	///Bruteforces algorithm
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum = 0;
			for(int k=i;k<=j;k++){
				///flip value
				if(arr[k] == 1){
					temp[k] = 0;
				}				
				else{
					temp[k] = 1;
				}
			}
			for(int k=1;k<=n;k++){
				sum = sum + temp[k];
			}
			if(sum > max){
				max = sum;
			}
			for(int k=1;k<=n;k++){
				temp[k] = arr[k];
			}
		}
	}
	printf("%d\n",max);
	return 0;
}