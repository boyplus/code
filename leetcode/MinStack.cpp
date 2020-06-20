#include <vector>
#include <iostream>
#include <stack>
using namespace std;
class MinStack {
public:
    stack<pair<int,int>> s;
    MinStack() {
        
    }
    void push(int x) {
        int mn = x;
        if(this->s.empty() == false && this->s.top().second < mn){
            mn = this->s.top().second;
        }
        this->s.push(make_pair(x,mn));
    }
    
    void pop() {
        this->s.pop();
    }
    
    int top() {
        return this->s.top().first;
    }
    
    int getMin() {
        return this->s.top().second;
    }
};
int main(){
	MinStack mn;
}