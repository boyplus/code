#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int i,j,k,n,a;
    scanf("%d",&n);
    int num[n];
    int max = -1,min=200000;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num[i]);
        if(num[i] < min)
        {
            min = num[i];
        }
    }
    scanf("%d",&a);
    //printf("%d %d\n",a,min);
    int num_test = a - min;
    vector<int> num2;
    for(i=0;i<n;i++)
    {
        if(num[i] <= num_test)
        {
            num2.push_back(num[i]);
        }
    }
    int my_size = num2.size();
    printf("use\n");
    for(i=0;i<my_size;i++)
    {
        printf("%d ",num2[i]);
    }
    int count=0;
    for(i=0;i<my_size;i++)
    {
        for(j=i+1;j<my_size;j++)
        {
            if(num2[i]+num2[j] == a)
            {
                count++;
            }
        }
    }
    printf("\n%d",count);
    return 0;
}
