#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class com{
public:
	int num,can;
	com(int num,int can){
		this->num = num;
		this->can = can;
	}
};
bool cmp(com& left,com& right){
	return left.num > right.num;
}
int main(){
	bool chk = false;
	vector<com> vec;
	int n,k,a,b,sum=0;
	scanf("%d %d",&n,&k);
	int tk = k;
	for(int i=0;i<n;i++){
		scanf("%d %d",&a,&b);
		vec.push_back(com(a,b));
	}
	sort(vec.begin(),vec.end(),cmp);
	int index = 0;
	for(int i=0;i<n;i++){
		if(vec[i].can == 0){
			sum = sum + vec[i].num;
			chk = true;
		}
		else{
			
			if(k>0){
				index = i;
				k--;
				sum = sum + vec[i].num;
			}
		}
	}
	if(chk==false && tk == 0){
		index--;
	}
	for(int i=index+1;i<n;i++){
		if(vec[i].can == 1){
			sum = sum - vec[i].num;
		}
	}
	printf("%d\n",sum);
	return 0;
}