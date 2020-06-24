#include <cstdio>
int ab(int a){
	return a < 0? -a : a;
}
int main(){
	int x1,y1,x2,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	int diffx = ab(x1-x2);
	int diffy = ab(y1-y2);
	if(x1 == x2){
		printf("%d %d %d %d\n",x1+diffy,y1,x1+diffy,y2);
	}
	else if(y1 == y2){
		printf("%d %d %d %d\n",x1,y1+diffx,x2,y1+diffx);
	}
	else if(diffy == diffx){
		printf("%d %d %d %d\n",x1,y2,x2,y1);
	}
	else{
		printf("-1\n");
	}
	return 0;
}