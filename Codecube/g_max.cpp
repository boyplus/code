#include <cstdio>
#include <stack>
#include <queue>
#include <utility>
using namespace std;
int arr[1000000],left[1000000],right[1000000];
stack<pair<int,int> > st;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		while(st.empty() == false && arr[i] >= st.top().first){
			st.pop();
		}
		int index=-1;
		if(st.empty() == false){
			index = st.top().second;
		}
		if(index == -1){
			left[i] = i;
		}
		else{
			left[i] = (i-index-1);
		}
		st.push(make_pair(arr[i],i));
	}
	while(st.empty() == false){
		st.pop();
	}
	for(int i=n-1;i>=0;i--){
		while(st.empty() == false && arr[i] >= st.top().first){
			st.pop();
		}
		int index=-1;
		if(st.empty() == false){
			index = st.top().second;
		}
		if(index == -1){
			right[i] = (n-i-1);
		}
		else{
			right[i] = (index-i-1);
		}
		st.push(make_pair(arr[i],i));
	}
	for(int i=0;i<n;i++){
		printf("%d ",left[i]+right[i]+1);
	}
	printf("\n");
}