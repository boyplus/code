#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int,int>& left,const pair<int,int>& right){
	return left.first < right.first;
}
vector<pair<int,int> > vec;
int main(){
	int n,a,b;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b); //price , quality  ai < aj and bi > bj
		vec.push_back(make_pair(a,b));
	}
	sort(vec.begin(),vec.end(),cmp);
	int maxB = vec[0].second;
	for(int i=1;i<n;i++){
		if(vec[i].second < maxB){
			printf("Happy Alex\n");
			return 0;
		}
		if(vec[i].second > maxB){
			maxB = vec[i].second;
		}
	}
	printf("Poor Alex\n");
	return 0;
}