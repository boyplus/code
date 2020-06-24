#include <cstdio>
#include <cstring>
int arr[100001];
int main(){
	int n,k,max=0,sum=0,index=0,first=-1;
	//first storage index of first element array 
	char str[20];
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s",str);
		if(strlen(str) == 2){
			if(str[0] == 'U' && str[1]=='R'){
				if(first == -1){
					arr[index++] = i;
					first = 0;
					sum++;
					if(sum > max){
						max = sum;
					}
				}
				else{
					while(i-arr[first]>=k){
						first++;
						sum--;
					}
					arr[index++] = i;
					sum++;
					if(sum > max){
						max = sum;
					}
				}
			}
		}
	}
	printf("%d\n",max);
	return 0;
}