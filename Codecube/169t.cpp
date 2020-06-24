#include <cstdio>
int fac(int num){
	int temp = num,now=2,count=0,ans=1;
	while(temp !=1){
		while(temp%now == 0 && temp!=0){
			temp/=now;
			count++;
		}
		ans = ans*(count+1);
		now++;
		count=0;
	}
	return ans;
}
int arr1[1000000],arr2[1000000];
int main(){
	int n,m,score=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&arr1[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d",&arr2[i]);
	}
	int index = 0;
	for(int i=0;i<m;i++){
		int factor = fac(arr2[i]);
		while(index < n && factor != fac(arr1[index])){
			index++;
		}
		//printf("in i = %d index = %d\n",i,index);
		if(index < n){
			score++;
		}
		else{
			break;
		}
	}
	printf("%d\n",score);
	return 0;
}