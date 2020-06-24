#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
    cout << fixed;
    int n,q;
    cin >> n >> q;
    while(q--){
    	if(n%10){
    		n--;
    	}
    	else{
    		n/=10;
    	}
    }
    cout << n << "\n";
	return 0;
}