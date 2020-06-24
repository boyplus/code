#include <cstdio>
#include <string>
#include <vector>
using namespace std;
char str[200001];
int min(int a,int b){
	return a < b? a : b; 
}
int main(){
	int n,count_one=0,count_zero = 0;
	scanf("%d",&n);
	scanf("%s",str);
	for(int i=0;i<n;i++){
		if(str[i] == '0'){
			count_zero++;
		}
		else{
			count_one++;
		}
	}
	printf("%d\n",n - (min(count_one,count_zero)*2));
	return 0;
}