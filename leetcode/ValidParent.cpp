#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(s[i] == '(' && s[j] == ')'){
                    s[i] = '-';
                    s[j] = '-';
                    break;
                }
            }
        }

        for(int i=s.size()-1;i>=0;i--){
            for(int j=i-1;j>=0;j--){
                if(s[i] == ')' && s[j] == '*'){
                    s[i] = '-';
                    s[j] = '-';
                    break;
                }
            }
        }

        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                if(s[i] == '(' && s[j] == '*'){
                    s[i] = '-';
                    s[j] = '-';
                    break;
                }
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i] == '(' || s[i] == ')'){
                return false;
            }
        }
        return true;
    }
};
int main(){
	Solution s;
	string a = "(*))";
	cout << s.checkValidString(a) << endl;
}