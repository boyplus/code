#include <cstdio>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
double square(double a){
	return a*a;
}
double min(double a,double b){
	if(a<b){
		return a;
	}
	return b;
}
vector<pair<double,double> > vec1,vec2;
double dist[1001];
int main(){
	int n,k;
	double x,y;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		///จุดสังเกตุ
		scanf("%lf %lf",&x,&y);
		vec1.push_back(make_pair(x,y));
	}
	for(int i=0;i<k;i++){
		///กล้องวงจรปิด
		scanf("%lf %lf",&x,&y);
		vec2.push_back(make_pair(x,y));
	}
	///reset distance to inf
	for(int i=0;i<n;i++){
		dist[i] = 1e20;
	}
	///find min distance to start point
	for(int i=0;i<n;i++){
		double x1 = vec1[i].first;
		double y1 = vec1[i].second;
		for(int j=0;j<k;j++){
			double x2 = vec2[j].first;
			double y2 = vec2[j].second;
			double temp = sqrt(square(x1-x2)+square(y1-y2));
			dist[i] = min(dist[i],temp);
		}
	}
	double max = 0;
	for(int i=0;i<n;i++){
		if(dist[i] > max){
			max = dist[i];
		}
	}
	printf("%.4lf\n",max);
	return 0;
}