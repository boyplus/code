#include <bits/stdc++.h>
using namespace std;
vector<int> vec1,vec2;
vector<int> lis1,lis2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
    cout << fixed;
    int n,num;
    cin >> n;
    for(int i=0;i<n;i++){
    	cin >> num;
    	vec1.push_back(num);
    	vec2.push_back(i);
    }
    for(int i=0;i<n;i++){
    	int pos = lower_bound(lis1.begin(),lis1.end(),vec1[i]) - lis1.begin();
    	if(pos == lis1.size()){
    		lis1.push_back(vec1[i]);
    	}
    	else{
    		lis1[pos] = vec1[i];
    	}
    }
    for(int i=0;i<lis1.size();i++){
    	cout << lis1[i] << " ";
    }
    cout << "\n";
	return 0;
}