#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> vec;
        for(int x: nums){
            if(x != 0){
                vec.push_back(x);
            }
        }
        int temp = vec.size();
        for(int i=0;i<nums.size()-temp;i++){
            vec.push_back(0);
        }
        nums = vec;
    }
};
int main(){
	Solution s;
	vector<int> vec = {0,1,0,3,12};
	s.moveZeroes(vec);
}