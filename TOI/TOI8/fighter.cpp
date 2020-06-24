#include <cstdio>
int main(){
	int p,num;
	scanf("%d",&p);
	int even = p,odd = p,countOdd=0,countEven=0;
	for(int i=0;i<p*2;i++){
		scanf("%d",&num);
		if(num%2){
			countOdd++;
			countEven = 0;
			if(countOdd >= 3){
				even-=3;
				if(even <= 0){
					printf("1\n");
					printf("%d\n",num);
					return 0;
				}
			}
			else{
				even--;
				if(even <= 0){
					printf("1\n");
					printf("%d\n",num);
					return 0;
				}
			}
		}
		else{
			countEven++;
			countOdd = 0;
			if(countEven >= 3){
				odd-=3;
				if(odd <= 0){
					printf("0\n");
					printf("%d\n",num);
					return 0;
				}
			}
			else{
				odd--;
				if(odd <= 0){
					printf("0\n");
					printf("%d\n",num);
					return 0;
				}
			}
		}
	}
	return 0;
}