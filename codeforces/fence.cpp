#include <cstdio>
#include <vector>
using namespace std;
vector<float> vec;
int main(){
	int angle;
	for(int i=3;i<=1000000;i++){
		float temp = (((float)i-2)*(180))/(float)i;
		vec.push_back(temp);
	}
	int T;
	scanf("%d",&T);
	while(T--){
		bool chk = false;
		scanf("%d",&angle);
		for(int j=0;j<vec.size();j++){
			if(angle == vec[j]){
				printf("YES\n");
				chk = true;
				break;
			}
		}
		if(chk == false){
			printf("NO\n");
		}
	}
	return 0;
}