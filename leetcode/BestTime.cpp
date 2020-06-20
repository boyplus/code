#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        prices.push_back(0);
        int now = prices[0], sum = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i-1] > prices[i]){
                sum = sum + (prices[i-1] - now);
                now = prices[i];
            }
        }
        return sum;
    }
};
int main(){
	Solution s;
	vector<int> vec = {7,6,4,3,1};
	cout << s.maxProfit(vec) << endl;
}