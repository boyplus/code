#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n_file[3000],all=0;
vector<int> file[3000];
int count[3000],n;
bool chk_error = true;
void call(int);
int main()
{
    int i,j,k,m,temp;
    scanf("%d",&n);
    for(i=1; i<=n; ++i)
    {
        scanf("%d",&n_file[i]);
        for(j=0; j<n_file[i]; ++j)
        {
            scanf("%d",&temp);
            file[i].push_back(temp);
        }
    }
    for(i=1; i<=n; ++i)
    {
        all=0;
        chk_error = true;
        call(i);
        if(chk_error)
            printf("NO\n");
        else
            printf("YES\n");
        memset(count, 0, sizeof(count));
    }
    return 0;
}
void call(int node)
{
    ++all;
    if(all > 3000)
    {
        chk_error = false;
        return;
    }
    int my_size = file[node].size();
    for(int i=0; i<my_size; ++i)
    {
        ++count[file[node].at(i)];
        if(count[file[node].at(i)] > 1)
        {
            chk_error = false;
            return;
        }
        call(file[node].at(i));
    }
}
