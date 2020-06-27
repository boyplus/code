#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        double sum = 0;
        for(int i=1;i<salary.size()-1;i++){
            sum+=salary[i];
        }
        return sum/(salary.size()-2);
    }
};
int main(){
	Solution s;
	vector<int> vec = {8000,9000,2000,3000,6000,1000};
    double ans = s.average(vec);
    cout << ans;

}