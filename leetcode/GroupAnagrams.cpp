#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<pair<string,int>> copy;
        for(int i=0;i<strs.size();i++){
            copy.push_back(make_pair(strs[i],i));
        }
        for(int i=0;i<copy.size();i++){
            sort(copy[i].first.begin(),copy[i].first.end());
        }
        for(int i=0;i<copy.size();i++){
            cout << copy[i].first << " " << copy[i].second << endl;
        }

        vector<pair<string,int>> now;
        now.push_back(copy[0]);
        for(int i=0;i<copy.size()-1;i++){
            
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<string> vec = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = s.groupAnagrams(vec);
    // for(int i=0;i<vec.size();i++){
    //     for(auto s: vec[i]){
    //         cout << s << " ";
    //     }
    //     cout << "\n";
    // }
    return 0;
}