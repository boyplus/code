#include <cstdio>
struct t{
	int left;
	int right;
	int val;
}data[2000000];
int cal(int u){
	int sum = data[u].val;
	if(data[u].left !=0){
		sum = sum + cal(data[u].left);
	}
	if(data[u].right != 0){
		sum = sum + cal(data[u].right);
	}
	return sum;
}
void del(int u){
	if(data[u].left !=0){
		del(data[u].left);
	}
	if(data[u].right !=0){
		del(data[u].right);
	}
	data[u].left = 0;
	data[u].right = 0;
	data[u].val = 0;
}
int main(){
	int n,k,u,l,r,p;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&p,&l,&r);
		data[i].left = l;
		data[i].right = r;
		data[i].val = p;
	}
	char q;
	for(int i=0;i<k;i++){
		scanf(" %c",&q);
		scanf(" %d",&u);
		///cal value
		if(q == 'a'){
			
			int value = cal(u);
			printf("%d\n",value);
		}
		else if(q == 'd'){
			del(u);
		}
	}
	return 0;
}