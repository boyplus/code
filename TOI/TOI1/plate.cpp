#include <cstdio>
#include <vector>
using namespace std;
int room[10001];
vector<int> q;
int main(){
	char cmd;
	int nRoom,nStudent,come,r,id;
	scanf("%d %d",&nRoom,&nStudent);
	for(int i=0;i<nStudent;i++){
		scanf("%d %d",&r,&id);
		room[id] = r;
	}
	while(1){
		scanf(" %c",&cmd);
		if(cmd == 'X'){
			printf("0\n");
			return 0;
		}
		if(cmd == 'E'){
			scanf("%d",&come);
			int nowRoom = room[come];
			int qSize = q.size();
			int index = -1;
			for(int i=0;i<qSize;i++){
				if(room[q[i]] == nowRoom){
					index = i;
				}
			}
			if(index == -1){
				q.push_back(come);
			}
			else{
				q.insert(q.begin()+index+1,come);
			}
		}
		if(cmd == 'D'){
			if(q.empty()){
				printf("empty\n");
			}
			else{
				printf("%d\n",q[0]);
				q.erase(q.begin());
			}
		}
	}
	return 0;
}