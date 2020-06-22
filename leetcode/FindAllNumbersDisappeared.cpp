#include <vector>
#include <iostream>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        map<int,bool> mp; 
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = true;
        }
        for(int i=1;i<=nums.size();i++){
            if(mp.find(i) == mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<int> vec = {4,3,2,7,8,2,3,1};
    vector<int> ans = s.findDisappearedNumbers(vec);
    for(int x:ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}