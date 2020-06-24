#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
int main(){
    int n,k,count=0,h1,h2,h3,mySize=0;
    scanf("%d %d",&n,&k);
    scanf("%d %d",&h1,&h2);
    if(h1 > h2){
    	vec.push_back(h1);
    	++mySize;
    }
    for(int i=3;i<n;++i){
    	scanf("%d",&h3);
    	if(h2 > h3 && h2 > h1){
    		vec.push_back(h2);
    		++mySize;
    	}
    	h1 = h2;
    	h2 = h3;
    }
    scanf("%d",&h3);
    if(h2 > h1 && h2 > h3){
    	vec.push_back(h2);
    	mySize++;
    }
    if(h3 > h2){
    	vec.push_back(h3);
    	mySize++;
    }
    count = mySize;
    sort(vec.begin(),vec.end());
    for(int i=0;i<mySize;++i){
        if(vec[i] == vec[i+1]){
            vec[i] = -1;
            --count;
        }
    }
    if(count < k){
    	if(count == 0){
    		printf("-1\n");
    		return 0;
    	}
        for(int i=0;i<mySize;++i){
            if(vec[i] != -1){
                printf("%d\n",vec[i]);
            }
        }
    }
    else{
        for(int i=mySize-1;i>=0 && k;--i){
            if(vec[i] != -1){
                printf("%d\n",vec[i]);
                --k;
            }
        }
    }
    return 0;
}