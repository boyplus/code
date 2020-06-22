#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        bool found = false, can = true, increasing = false;
        if(A.size() < 3){
            return false;
        }
        for(int i=0;i<A.size()-1;i++){
            if(found == false){
                if(A[i] < A[i+1]){
                    increasing = true;
                }
                if(A[i] == A[i+1]){
                    can = false;
                    break;
                } else if(A[i] > A[i+1]){
                    found = true;
                }
            } else{
                if(A[i] <= A[i+1]){
                    can = false;
                    break;
                }
            }
        }
        return can && found && increasing;
    }
};
int main(){
	Solution s;
	vector<int> vec = {9,8,7,6,5,4,3,2,1,0};
	cout << s.validMountainArray(vec) << endl;
}