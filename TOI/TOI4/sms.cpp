#include <cstdio>
#include <vector>
using namespace std;
vector<char> vec;
char sms[10][10] = {"","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
void gen(int btn,int click){
	int mod = 3;
	if(btn == 7 || btn == 9){
		mod = 4;
	}
	if(btn!=1){
		click = click%mod;
		if(click == 0){
			click = mod;
		}
		char temp = sms[btn][click-1];
		vec.push_back(temp);
	}
	else{
		while(!vec.empty() && click > 0){
			vec.pop_back();
			click--;
		}
	}
}
int main(){
	int n,click,h,v,btn;
	scanf("%d",&n);
	scanf("%d %d",&btn,&click);
	gen(btn,click);
	int now = btn;
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&h,&v,&click);
		now = now + h;
		now = now + (v*3);
		gen(now,click);
	}
	if(vec.empty()){
		printf("null");
	}
	else{
		int vecSize = vec.size();
		for(int i=0;i<vecSize;i++){
			printf("%c",vec[i]);
		}
	}
	printf("\n");
	return 0;
}