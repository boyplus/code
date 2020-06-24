#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> grow;
int main(){
	int k,num,sum = 0,count=0;
	scanf("%d",&k);
	for(int i=0;i<12;i++){
		scanf("%d",&num);
		grow.push_back(num);
	}
	sort(grow.begin(),grow.end());
	int index = 11;
	while(sum < k && index >= 0){
		sum = sum + grow[index];
		index--;
		count++; 
	}
	printf("%d\n",sum >= k ? count : -1);
	return 0;
}