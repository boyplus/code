#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec1,vec2,vec3;
int main(){
	int n,num,ans1 = 0,ans2 = 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		vec1.push_back(num);
	}
	for(int i=1;i<n;i++){
		scanf("%d",&num);
		vec2.push_back(num);
	}
	for(int i=2;i<n;i++){
		scanf("%d",&num);
		vec3.push_back(num);
	}
	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
	sort(vec3.begin(),vec3.end());
	for(int i=0;i<n;i++){
		if(vec1[i] != vec2[i]){
			ans1 = vec1[i];
			break;
		}
	}
	for(int i=0;i<vec2.size();i++){
		if(vec2[i] != vec3[i]){
			ans2 = vec2[i];
			break;
		}
	}
	printf("%d\n%d\n",ans1,ans2);
	return 0;
}