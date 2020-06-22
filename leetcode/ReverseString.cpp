#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0,j = s.size()-1;
        while(i < j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
};
int main(){
	Solution s;
	vector<char> vec = {'H','a','n','n','a','h'};
    s.reverseString(vec);
    for(char x:vec){
        cout << x ;
    }
    cout << endl;
    return 0;
}