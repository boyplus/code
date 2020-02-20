#include <cstdio>
#include <vector>
using namespace std;
vector<int> my_vec[100001];
int table[100001];
int main()
{
    int i,j,k,n,q,s,e;
    scanf("%d %d %d",&k,&n,&q);
    for(i=0; i<q; i++)
    {
        scanf("%d %d",&s,&e);
        my_vec[s].push_back(e);
    }
    int find_max = -1,position=0;
    for(i=1; i<=n; i++)
    {
        int my_size = my_vec[i].size();
        for(j=0; j<my_size; j++)
        {
            if(i!=1)
                if(table[i]==0)
                    break;
            position = my_vec[i].at(j);
            if(table[position]==0)
                table[position] = table[i]+1;
            else if(table[position]>table[i]+1)
                table[position] = table[i]+1;
            if(position>find_max && table[position]<=k)
                find_max = position;
        }
    }
    printf("%d",find_max);
    return 0;
}
