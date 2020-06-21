#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0,cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                cnt++;
                ans = max(ans,cnt);
            } else{
                cnt = 0;
            }
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<int> vec = {1,1,0,1,1,1};
	cout << s.findMaxConsecutiveOnes(vec) << endl;
}