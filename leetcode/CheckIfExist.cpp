#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr.size();j++){
                if(arr[i] == arr[j]*2 && i != j){
                    return true;
                }
            }
        }
        return false;
    }
};
int main(){
	Solution s;
	vector<int> vec = {3,1,7,11};
    cout << s.checkIfExist(vec) << endl;
	return 0;
};