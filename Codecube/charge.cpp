#include <cstdio>
long long arr[1000000];
int main(){
	long long n,k;
	scanf("%lld %lld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%lld",&arr[i]);
	}
	bool found = true;
	long long start = 1;
	long long ll = 1,rr = 1e15;
	while(ll <= rr){
		long long mid = (ll+rr)/2;
		long long power=0,count=0;
		bool can = true;
		for(int i=0;i<n;++i){
			if(power < arr[i]){
				power = mid;
				if(power < arr[i]){
					can = false;
					break;
				}
				else{
					power = power - arr[i];
				}
				count++;
			}
			else{
				power = power - arr[i];
			}
			if(count > k){
				can = false;
				break;
			}
		}
		if(count == k && can == true){
			start = mid;
			rr = mid-1;
		}
		else if(count < k && can){
			rr = mid-1;
		}
		else if(count > k || can == false){
			ll = mid+1;
		}
	}
	long long left = start,right = 1e15;
	long long last = start;
	while(left <= right){
		long long mid = (left+right)/2;
		long long power=0,count=0;
		bool can = true;
		for(int i=0;i<n;++i){
			if(power < arr[i]){
				power = mid;
				if(power < arr[i]){
					can = false;
					break;
				}
				else{
					power = power - arr[i];
				}
				count++;
			}
			else{
				power = power - arr[i];
			}
			if(count > k){
				can = false;
				break;
			}
		}
		if(count == k && can == true){
			last = mid;
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
	if(last == 1e15){
		printf("-1\n");
	}
	else{
		printf("%lld\n",last-start+1);
	}
	return 0;
}