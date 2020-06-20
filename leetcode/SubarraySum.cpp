#include <vector>
#include <iostream>
#include <queue>
#include <map>
using namespace std;
class Solution {
public:
    int dp[20005];
    int subarraySum(vector<int>& nums, int k){
        int cnt = 0;
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            if(i == 0){
                dp[i] = nums[i];
                mp[dp[i]].push_back(i);
            } else{
                dp[i] = dp[i-1]+nums[i];
                mp[dp[i]].push_back(i);
            }    
        }
        for(int i=0;i<nums.size();i++){
            int want = dp[i] - k;
            if(mp.find(want) != mp.end()){
                for(int j=0;j<mp[want].size();j++){
                    if(mp[want][j] < i){
                        cnt++;
                    }
                }
            }
            if(want == 0){
                cnt++;
            }
        }
        return cnt;
    }
};
int main(){
	Solution s;
	vector<int> v = {1,1,1};
	cout << s.subarraySum(v,2) << endl;
}