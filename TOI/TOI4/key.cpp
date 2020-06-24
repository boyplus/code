#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	char str1[200],str2[200],key[200];
	int len1,len2,index=0;
	scanf("%d %d",&len1,&len2);
	scanf("%s %s %s",str1,str2,key);
	for(int i=0;i<len2;i++){
		for(int j=0;j<len1;j++){
			vector<char> vec;
			vec.push_back(str1[j]);
			vec.push_back(str2[j]);
			vec.push_back(key[i]);
			sort(vec.begin(),vec.end());
			key[i] = vec[1];
		}
	}
	printf("%s\n",key);
	return 0;
}