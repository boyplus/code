#include <cstdio>
bool s[30],bi[30],def[30];
int main(){
	int n,num;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		s[i] = num;
		def[i] = num;
	}
	///binary counter
	int round = 1,cc=0,min = 1e9;
	for(int i=1;i<=n;i++){
		round*=2;
	}
	while(cc < round){
		///check
		int count = 0;
		bool can = true;
		for(int i=1;i<=n;i++){
			if(bi[i]){
				count++;
				s[i-1] = !s[i-1];
				s[i] = !s[i];
				s[i+1] = !s[i+1];
			}
		}
		for(int i=1;i<=n;i++){
			if(s[i]){
				can = false;
				break;
			}
		}
		if(can){
			if(count < min){
				min = count;
			}
		}
		///reset s
		for(int i=1;i<=n;i++){
			s[i] = def[i];
		}
		///increase
		int index = n;
		while(bi[index] && index > 1){
			bi[index] = 0;
			index--;
		}
		if(index >= 1){
			bi[index] = 1;
		}
		cc++;
	}
	if(min == 1e9){
		printf("-1\n");
	}
	else{
		printf("%d\n",min);
	}
	return 0;
}