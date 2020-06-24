#include <bits/stdc++.h>
using namespace std;
vector<int> vec;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
    cout << fixed;
    int n,k,num;
    cin >> n >> k;
    for(int i=0;i<n;i++){
    	cin >> num;
    	vec.push_back(num);
    }
    sort(vec.begin(),vec.end());
    int left = 1,right = (int)1e9;
    while(left <= right){
    	int mid = (left+right)/2;
    	int cnt = 0;
    	bool can = true;
    	for(int i=0;i<n;i++){
    		if(vec[i] <= mid){
    			cnt++;
    		}
    		if(cnt > k){
    			can = false;
    			break;
    		}
    	}
    	if(can && cnt == k){
    		cout << mid << "\n";
    		return 0;
    	}
    	if(cnt > k){
    		right = mid-1;
    	}
    	else{
    		left = mid+1;
    	}
    }
    cout << "-1\n";
	return 0;
}
/*
7 5
1 1 1 1 1 3 4
3 7 5 1 10 3 20

*/