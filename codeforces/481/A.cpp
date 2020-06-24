#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> vec,ans;
int fre[1001],idx[1001];
bool cmp(pair<int,int> left,pair<int,int> right){
	return left.second < right.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	int n,num;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> num;
		vec.push_back({num,i});
		fre[num]++;
		idx[num] = i;
	}
	for(int i=1;i<=1000;i++){
		if(fre[i]){
			ans.push_back({i,idx[i]});
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	cout << (int)ans.size() << "\n";
	for(int i=0;i<(int)ans.size();i++){
		cout << ans[i].first << " ";
	}
	cout << "\n";
	return 0;
}