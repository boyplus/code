#include <bits/stdc++.h>
using namespace std;
long long arr[300000],qsum[300000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
    cout << fixed;
    long long n,m,num;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
    	cin >> arr[i];
    	qsum[i] = qsum[i-1]+arr[i];
    }
    while(m--){
    	cin >> num;
    	long long left = 1,right = n;
    	long long ans = 1;
    	while(left <= right){
    		long long mid = (left+right)/2;
    		if(num == qsum[mid]){
    			ans = mid;
    			break;
    		}
    		else if(num > qsum[mid]){
    			ans = mid;
    			left = mid+1;
    		}
    		else{
    			right = mid-1;
    		}
    	}
    	if(qsum[ans] < num){
    		ans++;
    	}
    	cout << ans << " " << num - qsum[ans-1]<< "\n";
    }
	return 0;
}