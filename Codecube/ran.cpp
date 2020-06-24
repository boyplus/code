#include <cstdio>
#include <cmath>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
using namespace std;
int main(){
	srand(time(NULL));
	printf("10\n");
	for(int i=0;i<10;i++){
		printf("%d ",rand()%10+1);
	}
	printf("\n");
	return 0;
}