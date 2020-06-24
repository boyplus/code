#include <cstdio>
#include <string>
#include <iostream>
#include <unordered_map>
#include <limits.h>
using namespace std;
unordered_map<string,int> mp,chk;
string str[10000];
int main(){
	int N,val,Max = INT_MIN;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		cin >> str[i];
		scanf("%d",&val);
		mp[str[i]]+=val;
	}
	for(int i=0;i<N;i++){
		if(mp[str[i]] > Max){
			Max = mp[str[i]];
		}
	}
	for(int i=0;i<N;i++){
		if(mp[str[i]] == Max){
			if(chk[str[i]] == 0){
				cout << str[i] << " " << mp[str[i]] << "\n";
				chk[str[i]] = 1;
			}
		}
	}
	return 0;
}
