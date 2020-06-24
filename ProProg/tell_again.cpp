#include <cstdio>
#include <string.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		long long ans = 0;
		char a[200000] = "",b[200000] = "";
		int fre1[200000] = {0},fre2[200000] = {0};
		scanf("%s %s",a,b);
		int l1 = strlen(a);
		int l2 = strlen(b);
		if(l1 > l2){
			printf("0\n");
			continue;
		}
		for(int i=0;i<l1;++i){
			fre1[a[i]]++;
		}
		for(int i=0;i<l1;++i){
			fre2[b[i]]++;
		}
		///check start
		bool chk = true;
		///number
		for(int j='0';j<='9';++j){
			if(fre1[j] != fre2[j]){
				chk = false;
				break;
			}
		}
		///letter upper
		if(chk){
			for(int j = 'a';j<='z';++j){
				if(fre1[j] != fre2[j]){
					chk = false;
					break;
				}
			}
		}
		if(chk){
			for(int j='A';j<='Z';++j){
				if(fre1[j] != fre1[j]){
					chk = false;
					break;
				}
			}
			if(chk){
				bool eiei = false;
				for(int i=0;i<l1;i++){
					if(a[i] != b[i]){
						eiei = true;
						break;
					}
				}
				if(eiei == false){
					ans++;
				}
			}
		}
		int start = 0;
		for(int i = l1;i<l2;++i){
			fre2[b[start]]--;
			fre2[b[i]]++;
			bool cc = true;
			///number
			for(int j='0';j<='9';++j){
				if(fre1[j] != fre2[j]){
					cc = false;
					break;
				}
			}
			if(cc){
				///letter lower
				for(int j = 'a';j<='z';++j){
					if(fre1[j] != fre2[j]){
						cc = false;
						break;
					}
				}
				if(cc){
					for(int j='A';j<='Z';++j){
						if(fre1[j] != fre2[j]){
							cc = false;
							break;
						}
					}
				}
			}
			if(cc){
				bool temp = true;
				int count = 0;
				for(int x = start+1;x<=i;++x){
					if(a[count] != b[x]){
						temp = false;
						break;
					}
					++count;
				}
				if(temp){
					++ans;
				}
			}
			++start;
		}
		printf("%lld\n",ans);
	}
	return 0;
}