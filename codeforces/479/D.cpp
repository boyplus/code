#include <bits/stdc++.h>
using namespace std;
vector<long long> vec;
map<long long,bool> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
    cout << fixed;
    int n;
    long long num;
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> num;
    	mp[num] = true;
    	vec.push_back(num);
    }
    //try to start
    for(int i=0;i<n;i++){
    	bool can = true;
    	vector<long long> ans;
    	long long now = vec[i];
    	for(int j=1;j<n;j++){
    		ans.push_back(now);
    		long long temp1 = now*2;
    		long long temp2 = now/3;
    		if(mp.find(temp1) != mp.end()){
    			now = temp1;
    		}
    		else if(mp.find(temp2) != mp.end() && now % 3 == 0){
    			now = temp2;
    		}
    		else{
    			can = false;
    			break;
    		}
    	}
    	if(can){
    		ans.push_back(now);
    		for(int j=0;j<ans.size();j++){
    			cout << ans[j] << " ";
    		}
    		cout << "\n";
    		return 0;
    	}
    }
	return 0;
}