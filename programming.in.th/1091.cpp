#include <cstdio>
#include <vector>
using namespace std;
vector<int> my_vec[300001];
int table[300001];
int main()
{
    int i,j,k,n,m,a,b,temp,find_max=-1;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        if(a>b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        my_vec[a].push_back(b);
    }
    for(i=1;i<=n;i++)
    {
        int my_size = my_vec[i].size();
        for(j=0;j<my_size;j++)
        {
            int position = my_vec[i].at(j);
            if(table[position] == 0)
                table[position] = table[i]+1;
            else if(table[i]+1>table[position])
                table[position] = table[i]+1;
            if(table[position] > find_max)
                find_max = table[position];
        }
    }
    printf("%d",find_max+1);
    return 0;
}
