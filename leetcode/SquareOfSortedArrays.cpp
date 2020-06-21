#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(int i=0;i<A.size();i++){
            if(A[i] < 0) A[i] = -A[i];
        }
        sort(A.begin(),A.end());
        for(int i=0;i<A.size();i++){
            A[i]*=A[i];
        }
        return A;
    }
};
int main(){
	Solution s;
	vector<int> vec = {-7,-3,2,3,11};
	vector<int> ans = s.sortedSquares(vec);
    for(int x:ans){
        cout << x << " ";
    }
    cout << endl;
    return 0;
}