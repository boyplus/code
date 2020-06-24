#include <cstdio>
int ab(int a){
	if(a<0)
		return -a;
	return a;
}
int main(){
	int x,y,num;
	scanf("%d %d %d",&x,&y,&num);
	int sum = ab(x)+ab(y);
	if(sum == num){
		printf("Yes\n");
	}
	else{
		if(num > sum && num%2 == sum%2){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}