#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int one = 0,zero = 0,ans = 0;
        for(int i=0;i<nums.size();i++){
            int x = nums[i];
            if(x == 0) zero++;
            else one++;
            if(one == zero){
                ans = i+1;
            }
        }
        return ans;
    }
};
int main(){
    Solution s;
    vector<int> v = {1,0,0,0,1,1,1};
    cout << s.findMaxLength(v) << endl;
}