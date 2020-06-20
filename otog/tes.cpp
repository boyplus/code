#include <vector>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
	bool isHappy(int n) {
		set<int> s;
		while(true){
			int temp = n,sum = 0,x;
			s.insert(n);
			while(temp > 0){
				x = temp%10;
				sum+=x*x;
				temp/=10;
			}
			n = sum;
			if(sum == 1){
				return true;
			}
			if(s.find(sum) != s.end()){
				return false;
			}
		}
		return false;
	}
};
int main(){
	Solution s;
	cout << s.isHappy(12) << endl;
}