#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans = 0;
        vector<int> temp;
        for(int h:heights){
            temp.push_back(h);
        }
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            if(heights[i] != temp[i]){
                ans++;
            }
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<int> vec = {1,2,3,4,5};
    cout << s.heightChecker(vec) << endl;
    return 0;
}