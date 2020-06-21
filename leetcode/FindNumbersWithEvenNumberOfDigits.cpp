#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            int cnt = 0;
            while(nums[i] >= 1){
                nums[i]/=10;
                cnt++;
            }
            if(cnt%2 == 0){
                ans++;
            }
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<int> vec = {12,345,2,6,7896};
	cout << s.findNumbers(vec) << endl;
}