#include <vector>
#include <iostream>
using namespace std;
bool cmp(const pair<string,int>& left,const pair<string,int>& right){
    return left.first < right.first;
}
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
        sort(copy.begin(),copy.end(),cmp);
        vector<vector<pair<string,int>>> temp;
        pair<string,int> now = copy[0];
        vector<pair<string,int>> nowVec;
        nowVec.push_back(copy[0]);
        for(int i=1;i<=copy.size();i++){
            if(i == copy.size()){
                temp.push_back(nowVec);
            } else if(now.first == copy[i].first){
                nowVec.push_back(copy[i]);
            } else {
                temp.push_back(nowVec);
                nowVec.clear();
                now = copy[i];
                nowVec.push_back(now);
            }
        }
        for(int i=0;i<temp.size();i++){
            vector<string> tempAns; 
            for(int j=0;j<temp[i].size();j++){
                int idx = temp[i][j].second;
                tempAns.push_back(strs[idx]);
            }
            ans.push_back(tempAns);
            tempAns.clear();
        }
        return ans;
    }
};
int main(){
	Solution s;
	vector<string> vec = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = s.groupAnagrams(vec);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}