#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums){
        int sum = 0,ans = nums[0];
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans = max(ans,sum);
            ans = max(ans,nums[i]);
            if(sum < 0){
                sum = 0;
            }
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
	cout << s.maxSubArray(vec) << endl;
}