#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int idx = nums.size()-1;
        if(nums.size() == 0){
            return -1;
        }
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] > nums[i+1]){
                idx = i;
                break;
            }
        }

        for(int i=idx+1;i<nums.size();i++){
            vec.push_back(make_pair(nums[i],i));
        }
        for(int i=0;i<=idx;i++){
            vec.push_back(make_pair(nums[i],i));
        }

        int left = 0,right = nums.size()-1;
        while(left <= right){
            int mid = (left+right)/2;
            if(vec[mid].first == target){
                return vec[mid].second;
            } else if(vec[mid].first > target){
                right = mid-1;
            } else{
                left = mid+1;
            }
        }
        return -1;
    }
};
int main(){
	Solution s;
	vector<int> vec = {};
	cout << s.search(vec,5) << endl;
}