#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;
vector<long double> vec;
long double x;
int main(){
	long long t;
	vec.push_back(1);
	for(int i=2;i<=36;i++){
		vec.push_back(vec.back()*6);
	}
	scanf("%lld",&t);
	while(t--){
		bool chk = true;
		long long idx = 0;
		cin >> x;
		long double tempX = x;
		long long cnt = 0;
		bool ok = false;
		while(true){
			if(tempX == vec[idx]){
				while(tempX >= 1){
					if(tempX == 1){
						printf("%lld\n",cnt);
						ok = true;
						break;
					}
					tempX/=6;
					cnt++;
					if(tempX == 1){
						printf("%lld\n",cnt);
						ok = true;
						break;
					}
				}
				break;
			} else if(tempX < vec[idx]){
				tempX*=2;
				cnt++;
			} else{
				idx++;
				if(idx >= vec.size()){
					chk = false;
					break;
				}
			}
		}
		if(ok == false){
			cout << "-1" << endl;
		}
	}	
	return 0;
}