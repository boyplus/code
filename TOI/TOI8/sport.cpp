#include <cstdio>
int k,a,b;
int maxW,maxL;
char str[7000000] = "";
void rec(int win,int lose){
	if(win == maxW || lose == maxL){
		str[win+lose] = '\0';
		int len = win+lose;
		for(int i=0;i<len;i++){
			printf("%c ",str[i]);
		}
		printf("\n");
	}
	else{
		str[win+lose] = 'W';
		rec(win+1,lose);
		str[win+lose] = 'L';
		rec(win,lose+1);
	}
}
int main(){
	scanf("%d %d %d",&k,&a,&b);
	maxW = k-a;
	maxL = k-b;
	rec(0,0);
	return 0;
}