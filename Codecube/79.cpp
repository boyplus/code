#include <cstdio>
#include <vector>
using namespace std;
vector<int> num(1010);
int main()
{
    int i,j,count=0,now1=0,n;
    scanf("%d",&n);
    int now2 = n-1;
    for(i=0; i<n; ++i)
        scanf("%d",&num[i]);
    int n_2 = n/2;
    if(n%2)
        n_2++;
    for(int k=0; k<n_2; ++k)
    {
        if(num[now1] == now1+1)
            ++count;
        else
        {
            for(i=0; i<n; ++i)
            {
                if(num[i] == now1+1)
                {
                    num.insert(num.begin()+now1,now1+1);
                    num.erase(num.begin()+i+1);
                    break;
                }
            }
        }
        if(num[now2] == now2+1)
            ++count;
        else
        {
            for(i=0; i<n; ++i)
            {
                if(num[i] == now2+1)
                {
                    num.insert(num.begin()+now2+1,now2+1);
                    num.erase(num.begin()+i);
                    break;
                }
            }
        }
        ++now1;
        --now2;
    }
    if(n%2)
        --count;
    printf("%d\n",count);
    return 0;
}
