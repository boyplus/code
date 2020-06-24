#include <cstdio>
#include <vector>
using namespace std;
vector<long long> vec;
int main(){
	long long n,countMin=0,countMax=0,num,max = 0,min = 1e12;
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&num);
		vec.push_back(num);
		if(num > max){
			max = num;
		}
		if(num < min){
			min = num;
		}
	}
	for(int i=0;i<n;i++){
		if(vec[i] == max){
			countMax++;
		}
		if(vec[i] == min){
			countMin++;
		}
	}
	long long way = countMax*countMin;
	if(max == min){
		way = countMax*(countMax-1)/2;
	}
	printf("%lld %lld\n",max-min,way);
	return 0;
}