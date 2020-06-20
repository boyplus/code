#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1),right(n,1),ans(n,1);
        for(int i=1;i<n;i++){
            left[i] =left[i-1]*nums[i-1];
        }
        for(int i=n-1;i>=0;i--){
            right[i] = right[i+1]*nums[i+1];
        }
        for(int i=0;i<n;i++){
            ans[i] = left[i]*right[i];
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<int> v = {1,2,3,4};
    vector<int> ans = s.productExceptSelf(v);
	for(int x:ans){
        cout << x << " ";
    }
    return 0;
}