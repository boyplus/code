#include <cstdio>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;
bool check(char a){
	if(a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U' || a == 'Y'){
		return true;
	}
	return false;
}
int main(){
	string str;
	cin >> str;
	int cnt=0,max=0,index = 0;
	str.insert(str.begin(),'Y');
	while(index < str.size()){
		int start_index = index,now_index = index;
		while(check(str[now_index]) == false && now_index < str.size()){
			now_index++;
		}
		int num = now_index - start_index;
		if(num > max){
			max = num;
		}
		index = now_index+1;
	}
	printf("%d\n",max+1);
	return 0;
}