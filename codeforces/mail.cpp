#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
vector<pair<int,int> > vec;
bool cmp(const pair<int,int>& left,const pair<int,int>& right){
	return left.first < right.first;
}
int ab(int a){
	return a < 0 ? -a:a;
}
int min(int a,int b){
	return a < b ? a:b;
}
int max(int a,int b){
	return a>b?a:b;
}
int Max[100001],Min[100001];
int main(){
	int n,num;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		vec.push_back(make_pair(num,i));
	}
	sort(vec.begin(),vec.end(),cmp);
	///find min distance
	for(int i=0;i<n;i++){
		int id = vec[i].second;
		if(i == 0){
			Min[id] = ab(vec[i].first - vec[i+1].first);
		}
		else if(i == n-1){
			Min[id] = ab(vec[i].first - vec[i-1].first);	
		}
		else{
			Min[id] = min(ab(vec[i].first - vec[i-1].first),ab(vec[i].first - vec[i+1].first));
		}
	}
	///find max distance
	for(int i=0;i<n;i++){
		int id = vec[i].second;
		if(i == 0){
			Max[id] = ab(vec[i].first - vec[n-1].first);
		}
		else if(i == n-1){
			Max[id] = ab(vec[i].first - vec[0].first);
		}
		else{
			Max[id] = max(ab(vec[i].first - vec[0].first),ab(vec[i].first - vec[n-1].first));
		}
	}
	for(int i=0;i<n;i++){
		printf("%d %d\n",Min[i],Max[i]);
	}
	return 0;
}