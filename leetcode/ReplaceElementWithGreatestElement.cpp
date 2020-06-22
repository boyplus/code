#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int mx = -1;
        for(int i=arr.size()-1;i>=0;i--){
            int temp = arr[i];
            arr[i] = mx;
            mx = max(temp,mx);
        }
        return arr;
    }
};
int main(){
	Solution s;
	vector<int> vec = {17,18,5,4,6,1};
    vector<int> ans = s.replaceElements(vec);
	for(int x:ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}