#include <cstdio>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
unordered_map<string,int> mp;
int main(){
	string str;
	int T;
	scanf("%d",&T);
	while(T--){
		cin >> str;
		if(mp[str] == 0){
			mp[str] = 1;
			cout << "OK\n";
		}
		else{
			cout << str << mp[str] << endl;
			mp[str]++;
		}
	}
	return 0;
}