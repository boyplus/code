#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int i,j,k,n,temp;
    scanf("%d",&n);
    int L[n],H[n],R[n];
    vector<int> ans;
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&L[i],&H[i],&R[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(L[i] > L[j])
            {
                temp = L[i];
                L[i] = L[j];
                L[j] = temp;
                temp = H[i];
                H[i] = H[j];
                H[j] = temp;
                temp = R[i];
                R[i] = R[j];
                R[j] = temp;
            }
        }
    }
    printf("After sort\n");
    for(i=0;i<n;i++)
    {
        printf("%d %d %d\n",L[i],H[i],R[i]);
    }
    ans.push_back(L[0]);
    ans.push_back(H[0]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            //if()
        }
    }
    return 0;
}
