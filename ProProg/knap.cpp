#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
class item{
public:
	int val;
	int weight;
	float cost;
	item(int val,int weight,float cost){
		this->val = val;
		this->weight = weight;
		this->cost = cost;
	}
};
int v[100000],w[100000];
vector<item> vec;
int main(){
	float maxW;
	int n;
	scanf("%f %d",&maxW,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&w[i]);
	}
	for(int i=0;i<n;i++){
		float temp = (float)v[i]/(float)w[i];
		vec.push_back(item(v[i],w[i],temp));
	}
	for(int i=0;i<n;i++){
		printf("val = %d weight = %d cost = %f\n",vec[i].val,vec[i].weight,vec[i].cost);
	}
	return 0;
}