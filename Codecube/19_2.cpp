#include <cstdio>
#include <vector>
using namespace std;
vector<int> vec(1010);
int main()
{
	int i,j,n,k;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",&vec[i]);
	int vec_size = n,temp_k = k;
	while(k--)
	{
		for(i=0;i<vec_size-1;i++)
		{
			if(vec[i] > vec[i+1])
			{
				vec.erase(vec.begin()+i);
				vec_size--;
				break;
			}
		}
	}
	int temp = n - temp_k;
	for(i=0;i<temp;i++)
		printf("%d ",vec[i]);
	return 0;
}
