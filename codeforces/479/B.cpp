#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
    cout << fixed;
    int n,mx = 0;
    string str;
    cin >> n >> str;	
    for(int i=1;i<n;i++){
    	string newstr = "";
    	newstr.push_back(str[i-1]);
    	newstr.push_back(str[i]);
    	mp[newstr]++;
    }
    string ans = "";
    for(int i=1;i<n;i++){
    	string newstr = "";
    	newstr.push_back(str[i-1]);
    	newstr.push_back(str[i]);
    	if(mp[newstr] > mx){
    		mx = mp[newstr];
    		ans = newstr;
    	}
    }
    cout << ans << "\n";
	return 0;
}