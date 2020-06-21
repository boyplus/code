#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        int i = 0,j = 0;
        while(i < m || j < n){
            if(i >= m){
                ans.push_back(nums2[j++]);
                continue;
            }
            if(j >= n){
                ans.push_back(nums1[i++]);
                continue;
            }
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i++]);
            } else{
                ans.push_back(nums2[j++]);
            }
        }
        nums1 = ans;
    }
};
int main(){
	Solution s;
	vector<int> vec1 = {1,2,3,0,0,0};
    vector<int> vec2 = {2,5,6};
    int m = 3,n = 3;
	s.merge(vec1,m,vec2,n);
    return 0;
}