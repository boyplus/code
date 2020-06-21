#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
    	vector<int> ans;
        for(int i=0;i<arr.size();i++){
        	if(arr[i] == 0){
        		ans.push_back(0);
        		if(ans.size() >= arr.size()) break;
        		ans.push_back(0);
        		if(ans.size() >= arr.size()) break;
        	} else {
        		ans.push_back(arr[i]);
        		if(ans.size() >= arr.size()) break;
        	}
        }
        arr = ans;
    }
};
int main(){
	Solution s;
	vector<int> vec = {1,0,2,3,0,4,5,0};
	s.duplicateZeros(vec);
	return 0;
};