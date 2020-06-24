#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class activity{
public:
	int start;
	int end;
	activity(int start,int end){
		this->start = start;
		this->end = end;
	}
};
int Start[1000000],End[1000000];
bool cmp(const activity& left,const activity& right){
	return left.end < right.end;
}
int main(){
	vector<activity> vec;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&Start[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&End[i]);
	}
	for(int i=0;i<n;i++){
		vec.push_back(activity(Start[i],End[i]));
	}
	sort(vec.begin(),vec.end(),cmp);
	int temp = 0,c=0;
	for(int i=0;i<n;i++){
		if(vec[i].start >= temp){
			temp = vec[i].end;
			c++;
		}
	}
	printf("%d\n",c);
	return 0;
}