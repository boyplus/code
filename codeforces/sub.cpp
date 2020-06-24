#include <cstdio>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,arr[200000] = {0},sum=0,qsum[200000] = {0};
		int Max1 = -1000000,Max2 = -1000000;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			arr[i]=0;
			qsum[i]=0;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		for(int i=0;i<n;i++){
			qsum[i] = qsum[i-1] + arr[i];
			if(qsum[i] > Max1){
				Max1 = qsum[i];
			}
			if(qsum[i] < 0){
				qsum[i] = 0;
			}
		}
		bool chk = false;
		for(int i=0;i<n;i++){
			if(arr[i] > 0){
				sum = sum + arr[i];
				Max2 = sum;
				chk = true;
			}
		}
		if(chk == false){
			for(int i=0;i<n;i++){
				if(arr[i] > Max2){
					Max2 = arr[i];
				}
			}
		}
		printf("%d %d\n",Max1,Max2);
	}

	return 0;
}