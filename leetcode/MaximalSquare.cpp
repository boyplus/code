#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		int ans = 0;
		for(int i=0;i<matrix.size();i++){
			for(int j=0;j<matrix[i].size();j++){

				if(matrix[i][j] == '1'){
					int checkSize = 1,nowSize = 1;
					bool can = true;
					while(true){
						can = true;
						int downRightY =  i+checkSize-1;
						int topRightX = j+checkSize-1;
						int downRightX = j+checkSize-1;
						int downLeftY = i+checkSize-1;
						
						if(downRightY >= matrix.size() || topRightX >= matrix[0].size()){
							can = false;
							break;
						}

						for(int k=i;k<=downRightY;k++){
							if(matrix[k][topRightX] != '1'){
								can = false;
								break;
							}
						}

						for(int k=j;k<=downRightX;k++){
							if(matrix[downLeftY][k] != '1'){
								can = false;
								break;
							}
						}

						if(can == true){
							nowSize = checkSize;
							checkSize++;	
						} else {
							break;
						}
					}
					ans = max(ans,nowSize);
				}
			}
		}
		return ans*ans;
	}
};
int main(){
	Solution s;
	vector<vector<char>> vec = 
	{
		{'1','0','1','0','0'},
		{'1','0','1','1','1'},
		{'1','1','1','1','1'},
		{'1','1','0','1','0'},
	};
	cout << s.maximalSquare(vec) << endl;
}