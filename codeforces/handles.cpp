#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s1[1001],s2[1001];
vector<pair<string,string> > vec;
bool chk[1001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i=0;i<n;i++){
		if(chk[i] == false){
			chk[i] = true;
			string now = s2[i];
			for(int j=i+1;j<n;j++){
				if(s1[j] == now){
					chk[j] = true;
					now = s2[j];
				}
			}
			vec.push_back(make_pair(s1[i],now));
		}
	}
	cout << vec.size() << endl;
	for(int i=0;i<vec.size();i++){
		cout << vec[i].first << " " << vec[i].second << endl;
	}
	return 0;
}