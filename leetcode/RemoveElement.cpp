#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> vec;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != val){
                vec.push_back(nums[i]);
            }
        }
        nums = vec;
        return vec.size();
    }
};
int main(){
	Solution s;
	vector<int> vec = {3,2,2,3};
	int ans = s.removeElement(vec,3);
    cout << ans << endl;
	return 0;
};