#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;
vector<char> ans;
int main(){
	int n,now=1;
	scanf("%d",&n);
	while(n--){
		vector<int> code;
		char str[20] = "";
		scanf("%s",str);
		int length = strlen(str);
		for(int i=0;i<length;i+=2){
			if(now == 1){
				if(str[i] == '0' && str[i+1] == '0'){
					code.push_back(0);
				}
				else if(str[i] == '1' && str[i+1] == '1'){
					now = 2;
					code.push_back(1);
				}
			}
			else if(now == 2){
				if(str[i] == '0' && str[i+1] == '1'){
					now = 4;
					code.push_back(1);
				}
				else if(str[i] == '1' && str[i+1] == '0'){
					now = 3;
					code.push_back(0);
				}
			}
			else if(now == 3){
				if(str[i] == '0' && str[i+1] == '0'){
					now = 2;
					code.push_back(1);
				}
				else if(str[i] == '1' && str[i+1] == '1'){
					now = 1;
					code.push_back(0);
				}
			}
			else if(now == 4){
				if(str[i] == '1' && str[i+1] == '0'){
					code.push_back(1);
				}
				else if(str[i] == '0' && str[i+1] == '1'){
					now = 3;
					code.push_back(0);
				}
			}
		}
		int codeSize = code.size(),fre=1;
		int sum = 0;
		for(int i=codeSize-1;i>=0;i--){
			sum = sum+(code[i]*fre);
			fre*=2;
		}
		if(sum>=65 && sum<= 90){
			ans.push_back(sum);
		}
	}
	int ansSize = ans.size();
	for(int i=0;i<ansSize;i++){
		printf("%c",ans[i]);
	}
	printf("\n");
	return 0;
}