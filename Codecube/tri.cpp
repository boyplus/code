#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
double x[1001],y[1001];
class dot{
public:
	double m;
	int index1,index2;
	dot(double m,int index1,int index2){
		this->m = m;
		this->index1 = index1;
		this->index2 = index2;
	}
};
vector<dot> vec;
bool cmp(const dot& left,const dot& right){
	return left.m < right.m;
}
int main(){
	int n;
	long long count = 0,answer = 1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf %lf",&x[i],&y[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			double dely1 = y[i] - y[j];
			double delx1 = x[i] - x[j];
			double m1 = 1e9;
			if(delx1 != 0){
				m1 = dely1/delx1;
			}
			vec.push_back(dot(m1,i,j));
		}
	}
	sort(vec.begin(),vec.end(),cmp);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int left = 0,right = vec.size();
			double dely1 = y[i] - y[j];
			double delx1 = x[i] - x[j];
			double m1 = 1e9;
			if(delx1 != 0){
				m1 = dely1/delx1;
			}
			int ans = -1;
			while(left <= right){
				int mid = (left+right)/2;
				if(vec[mid].m < m1){
					left = mid+1;
				}
				if(vec[mid].m > m1){
					right = mid-1;
				}
				else if(vec[mid].m == m1){
					ans = mid;
					break;
				}
			}
			while(vec[ans-1].m == m1 && ans > 0){
				ans--;
			}
			while(vec[ans].m == m1 && ans < vec.size()){
				if(vec[ans].index1 == j){
					count++;
				}
				ans++;
			}
		}
	}
	for(int i=n;i+3>n;i--){
		answer*=i;
	}
	answer/=6;
	answer-=count;
	printf("%lld\n",answer);
	return 0;
}