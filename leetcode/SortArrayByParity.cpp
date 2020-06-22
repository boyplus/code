#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even,odd;
        for(int x:A){
            if(x%2 == 0){
                even.push_back(x);
            } else{
                odd.push_back(x);
            }
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end());
        int idx = 0;
        for(int x:even){
            A[idx++] = x;
        }
        for(int x:odd){
            A[idx++] = x;
        }
        return A;
    }
};
int main(){
	Solution s;
	vector<int> vec = {3,1,2,4};
    vector<int> ans = s.sortArrayByParity(vec);
	for(int x:ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}