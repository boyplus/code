#include <cstdio>
#include <vector>
using namespace std;
vector<int> vec[4];
int main(){
	int n,num;
	scanf("%d",&n);
	int min = n;
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		vec[num].push_back(i);
	}
	for(int i=1;i<=3;i++){
		if(vec[i].size() < min){
			min = vec[i].size();
		}
	}
	printf("%d\n",min);
	for(int i=0;i<min;i++){
		printf("%d %d %d\n",vec[1][i],vec[2][i],vec[3][i]);
	}
	return 0;
}