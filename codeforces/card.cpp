#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<pair<int,int> > vec;
bool cmp(const pair<int,int>& left,const pair<int,int>& right){
	return left.first < right.first;
}
int main(){
	int n,num,j;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		vec.push_back(make_pair(num,i));
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=0,j=n-1;i<n/2;i++,j--){
		printf("%d %d\n",vec[i].second+1,vec[j].second+1);
	}
	return 0;
}