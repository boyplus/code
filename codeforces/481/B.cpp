#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
    cout << fixed;
    int n,cnt = 0;
    string str;
    cin >> n >> str;
    bool chk = true;
    while(chk){
    	chk = false;
    	for(int i=2;i<(int)str.size();i++){
    		if(str[i] == 'x' && str[i-1] == 'x' && str[i-2] == 'x'){
    			str.erase(str.begin()+i);
    			cnt++;
    			chk = true;
    		}
    	}
    }	
    cout << cnt << "\n";
	return 0;
}