#include <cstdio>
#include <math.h>
#include <vector>
using namespace std;
vector<int> arr;
bool cc(int num){
	if(num == 0 || num == 1){
		return false;
	}
	float temp = sqrt(num);
	for(int i=2;i<=temp;i++){
		if(num % i == 0){
			return false;
		}
	}
	return true;
}
int main(){
	for(int i=2;i<=1000000;i++){
		if(cc(i)){
			arr.push_back(i);
		}
	}
	long long T,num;
	scanf("%lld",&T);
	while(T--){
		bool chk = false;
		scanf("%lld",&num);
		double temp = sqrt(num);
		long long tt = (long long)temp;
		if(temp == tt){
			int left = 0,right = arr.size();
			while(left <= right){
				int mid = (left+right)/2;
				if(arr[mid] == tt){
					chk = true;
					break;
				}
				else if(arr[mid] > tt){
					right = mid-1;
				}
				else{
					left = mid+1;
				}
			}
			if(chk == true){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}