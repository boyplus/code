#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int mx1 = nums[0],mx2 = nums[0],mx3 = nums[0];
        for(int x:nums){
            mx1 = max(mx1,x);
        }
        bool found1 = false,found2 = false;
        mx2 = INT_MIN;
        mx3 = INT_MIN;
        for(int x:nums){
            if(x != mx1){
                mx2 = max(mx2,x);
                found1 = true;
            }
        }
        for(int x:nums){
            if(x != mx1 && x != mx2){
                mx3 = max(mx3,x);
                found2 = true;
            }
        }
        if(found2 == false){
            return mx1;
        } else{
            return mx3;
        }
    }
};
int main(){
	Solution s;
	vector<int> vec = {1,2};
    cout << s.thirdMax(vec) << endl;
    return 0;
}