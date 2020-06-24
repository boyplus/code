#include <cstdio>
#include <vector>
#include <string.h>
using namespace std;
int arr1[20],arr2[20],arr3[20];
vector<int> vec;
int main(){
	int index=1,k1,k2,k3;
	char str[300] = "",key[10] = "";
	scanf("%s %s",key,str);
	k1 = key[0] - 48;
	k2 = key[1] - 48;
	k3 = key[2] - 48;
	int t1=k1,t3=k3;
	///reset key
	while(index <= 9){
		arr1[index] = k1;
		arr2[index] = k2;
		arr3[index] = k3;
		k1++;
		k2++;
		k3++;
		if(k1 > 9){
			k1 = 1;
		}
		if(k2 > 9){
			k2 = 1;
		}
		if(k3 > 9){
			k3 = 1;
		}
		index++;
	}
	int length = strlen(str);
	for(int i=0;i<length;i++){
		int num = str[i]-48;
		num = arr1[num];
		num = arr2[num];
		num = arr3[num];
		vec.push_back(num);
		///change arr1
		int index = 1,temp = arr1[t1+1];
		while(index<=9 && temp!=0){
			if(temp > 9){
				temp = 1;
			}
			arr1[index] = temp;
			temp++;
			index++;
		}
		//change arr2
		index = 1,temp = arr2[9];
		while(index <= 9){
			arr2[index] = temp;
			temp++;
			if(temp > 9){
				temp = 1;
			}
			index++;
		}
		///change arr3
		index = 1,temp = arr3[t3+1];
		while(index <= 9 && temp !=0){
			if(temp > 9){
				temp = 1;
			}
			arr3[index] = temp;
			temp++;
			index++;
		}
		
	}
	for(int i=0;i<length;i++){
		printf("%d",vec[i]);
	}
	return 0;
}