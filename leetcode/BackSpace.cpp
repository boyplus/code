#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool backspaceCompare(string S, string T){
    	stack<char> q1,q2;
    	int s1 = 0,s2 = 0;
    	for(char s:S){
    		if(s == '#'){
    			if(q1.empty() == false){
    				q1.pop();
    				s1--;
    			}
    		} else{
    			q1.push(s);
    			s1++;
    		}
    	}

    	for(char t:T){
    		if(t == '#'){
    			if(q2.empty() == false){
    				q2.pop();
    				s2--;
    			}
    		} else{
    			q2.push(t);
    			s2++;
    		}
    	}
    	if(s1 == s2){
    		while(q1.empty() == false && q2.empty() == false){
    			char a = q1.top(), b = q2.top();
    			if(a != b){
    				return false;
    			}
    			q1.pop();
    			q2.pop();
    		}
    	} else{
    		return false;
    	}
    	return true;
    }
};
int main(){
	Solution s;
	string a = "ab##", b = "c#d#";
	cout << s.backspaceCompare(a,b) << endl;
}