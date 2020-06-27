#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int longestSubarray(vector<int>& nums) {
		int cnt = 0,mx = 0;
		vector<pair<int,int>> vec;
		bool chk = false;
		for(int i=0;i<nums.size();i++){
			if(nums[i] == 1){
				vec.push_back(make_pair(i,i));
				while(i < nums.size() && nums[i] == 1){
					vec.back().second = i;
					i++;
				}
			}
		}
		for(int i=0;i<vec.size();i++){
			int temp = vec[i].second - vec[i].first+1;
			mx = max(mx,temp);
			if(i != vec.size()-1 && vec[i].second+2 == vec[i+1].first){
				int temp = vec[i+1].second - vec[i].first;
				mx = max(mx,temp);
			}
		}
		if(vec.size() == 1 && vec[0].first == 0 && vec[0].second == nums.size()-1){
			mx = nums.size()-1;
		}
		return mx;
	}
};
int main(){
	Solution s;
	vector<int> vec = {1,1,1};
	int ans = s.longestSubarray(vec);
	cout << ans;
}