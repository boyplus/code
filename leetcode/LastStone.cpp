#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class Solution {
public:
    priority_queue<int> pq;
    int lastStoneWeight(vector<int>& stones){
        for(int s:stones){
            pq.push(s);
        }
        while(pq.empty() == false){
            if(pq.size() == 1){
                int x = pq.top();
                pq.pop();
                return x;
            }
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(x != y){
                pq.push(y-x);
            }
        }
        return 0;
    }
};
int main(){
	Solution s;
	vector<int> v = {2,7,4,1,8,1};
	cout << s.lastStoneWeight(v) << endl;
}