#include <stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int one[n],three_four[n],one_two[n],one_four[n],one_eight[n];
    int one_=0,three_four_=0,one_two_=0,one_four_=0,one_eight_=0;
    for(i=0; i<n; i++)
    {
        scanf("%d %d %d %d %d",&one[i],&three_four[i],&one_two[i],&one_four[i],&one_eight[i]);
        one_ += one[i];
        three_four_+=three_four[i];
        one_two_+=one_two[i];
        one_four_+=one_four[i];
        one_eight_+=one_eight[i];
        while(three_four_ >=1)
        {
            one_four_++;
            one_++;
            three_four_-=1;
        }
        while(one_eight_ >=2)
        {
            one_four_++;
            one_eight_-=2;
        }
        while(one_four_ >= 2)
        {
            one_two_++;
            one_four_-=2;
        }
        while(one_two_ >=2)
        {
            one_++;
            one_two_-=2;
        }
        printf("in %d %d %d %d %d\n",one_,three_four_,one_two_,one_four_,one_eight_);
    }
    while(three_four_ >=2)
    {
        one_four_++;
        one_++;
        three_four_-=1;
    }
    while(one_eight_ >=2)
    {
        one_four_++;
        one_eight_-=2;
    }
    while(one_four_ >= 2)
    {
        one_two_++;
        one_four_-=2;
    }
    while(one_two_ >=2)
    {
        one_++;
        one_two_-=2;
    }
    printf("%d",one_);
    return 0;
}
