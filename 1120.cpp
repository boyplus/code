#include <cstdio>
using namespace std;
int num[1000001];
int main()
{
    int i,j,k,n,m,count=2,count_2=0,ans=1,temp=1;
    for(int i=1;i<=100000;i++)
    {
        ans = 1;
        count=2;
        temp=i;
        while(temp >1)
        {
            while(temp%count==0)
            {
                temp = temp/count;
                count_2++;
            }
            count++;
            ans = ans*(count_2+1);
            count_2=0;
        }
        num[i] = ans;
        //printf("%d\n",num[i]);
    }

    return 0;
}
