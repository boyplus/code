#include <cstdio>
#include <unordered_map>
#include <string>
#include <iostream>
using namespace std;
unordered_map<string,int> chk1,chk2,chkAll,sayed1,sayed2;
string A[2000],B[2000];
int main(){
	int n,m,round = 0,count1=0,count2=0;
	scanf("%d %d",&n,&m);
	int allRound = n+m;
	for(int i=0;i<n;++i){
		cin >> A[i];
		chk1[A[i]] = 1;
	}
	for(int i=0;i<m;++i){
		cin >> B[i];
		chk2[B[i]] = 1;
	}
	///same word in player 1 and player 2
	for(int i=0;i<n;++i){
		if(chk1[A[i]] && chk2[A[i]]){
			chkAll[A[i]] = 1;
		}
	}
	while(round < allRound){
		//turn PalandBall
		if(round%2 == 0){
			bool chk = false;
			for(int i=0;i<n;++i){
				if(chkAll[A[i]]){
					if(sayed1[A[i]] == 0 && sayed2[A[i]] == 0){
						sayed1[A[i]] = 1;
						sayed2[A[i]] = 1;
						++count1;
						chk = true;
						break;
					}
				}
			}
			if(chk == false){
				for(int i=0;i<n;++i){
					if(sayed1[A[i]] == 0 && sayed2[A[i]] == 0){
						sayed1[A[i]] = 1;
						sayed2[A[i]] = 1;
						count1++;
						break;
					}
				}
			}
		}
		///turn Enemy
		else{
			bool chk = false;
			for(int i=0;i<m;++i){
				if(chkAll[B[i]]){
					if(sayed2[B[i]] == 0 && sayed1[B[i]] == 0){
						sayed2[B[i]] = 1;
						sayed1[B[i]] = 1;
						count2++;
						chk = true;
						break;
					}
				}
			}
			if(chk == false){
				for(int i=0;i<m;++i){
					if(sayed2[B[i]] == 0 && sayed1[B[i]] == 0){
						sayed2[B[i]] = 1;
						sayed1[B[i]] = 1;
						count2++;
						break;
					}
				}
			}
		}
		++round;
	}
	if(count1 > count2){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
}