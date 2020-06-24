#include <cstdio>
int m,n;
int ans[10] = {0};
bool chk[10] = {false};
double num[10][10] = {0},min = 999999999999999,temp[10][10]={0};
int ab(int a){
	if(a<0)
		return a*-1;
	return a;
}
void rec(int count){
	if(count == m*n){
		///reset num
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				num[i][j] = temp[i][j];
			}
		}
		///calculate sum
		double sum = 0;
		for(int i=0;i<m*n;i++){
			int y=0,x=0,count=0;
			bool find = false;
			for(int j=0;j<m;j++){
				for(int k=0;k<n;k++){
					if(count == ans[i]){
						y = j;
						x = k;
						find = true;
						break;
					}
					count++;
				}
				if(find){
					break;
				}
			}
			double temp = num[y][x];
			sum = sum+temp;
			for(int j=0;j<m;j++){
				for(int k=0;k<n;k++){
					if(j == y && k == x){
						continue;
					}
					int diffY = ab(j - y);
					int diffX = ab(k - x);
					if(diffY <= 1 && diffX <= 1){
						num[j][k] = num[j][k]+(0.10*num[y][x]);
					}
				}
			}
		}
		if(sum < min){
			min = sum;
		}
	}
	else{
		for(int i=0;i<m*n;i++){
			if(chk[i] == false){
				chk[i] = true;
				ans[count] = i;
				rec(count+1);
				chk[i] = false;
			}
			
		}
	}
	
}
int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%lf",&num[i][j]);
			temp[i][j] = num[i][j];
		}
	}
	rec(0);
	printf("%.2lf\n",min);
	return 0;
}