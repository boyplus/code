#include <cstdio>
#include <cstring>
using namespace std;
long long pos[1000000],lum[1000000];
int main(){
	long long n,m,k,l;
	scanf("%lld %lld %lld %lld",&n,&m,&k,&l);
	for(int i=0;i<n;i++){
		scanf("%lld",&pos[i]);
	}
	for(int i=0;i<k;++i){
		long long count=0,start = 0;
		bool chk[1000000] = {false};
		for(int j=0;j<m;++j){
			scanf("%lld",&lum[j]);
			long long low = lum[j] - l;
			long long high = lum[j] + l;
			///Binary search to find answer
			long long left = 0,right = n-1,ans=0;
			bool can = false;
			//printf("low = %lld high = %lld\n",low,high);
			//printf("left = %lld right = %lld\n",left,right);
			while(left <= right){
				long long mid = (left+right)/2;
				//printf("(%lld,%lld,%lld)\n",left,mid,right);
				if(pos[mid] >= low && pos[mid] <= high){
					//printf("in %lld\n",pos[mid]);
					right = mid-1;
					ans = mid;
					can = true;
				}
				else if(pos[mid] > high){
					right = mid-1;
				}
				else{
					left = mid+1;
				}
			}
			if(can == false){
				continue;
			}
			//printf("ans = %lld left = %lld right = %lld\n",ans,left,right);
			for(int x=ans;x<n;++x){
				if(pos[x] <= high){
					chk[x] = true;
				}
				else{
					break;
				}
			}
		}
		for(int x=0;x<n;++x){
			if(chk[x]){
				++count;
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}