#include <cstdio>
struct domino
{
    int x;
    int h;
    int distance_right;
    int distance_left;
} data[100000];
int sum_fall_right[100000],sum_fall_left[100000],sum_all_right[100000],sum_all_left[100000];
int main()
{
    int i,j,k,m,n,max_right=-1,max_left=-1,ans_right=0,ans_left=0;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
    {
        scanf("%d %d",&data[i].x,&data[i].h);
        data[i].distance_right = data[i].x + data[i].h;
        data[i].distance_left = data[i].x - data[i].h;
    }
    for(i=0; i<n; ++i)
    {
        int temp_po_right = i+1;
        while(data[i].distance_right > data[temp_po_right].x && temp_po_right <n)
        {
            ++sum_fall_right[i];
            ++temp_po_right;
        }
        int temp_po_left = i-1;
        while(data[i].distance_left < data[temp_po_left].x && temp_po_left >= 0)
        {
            ++sum_fall_left[i];
            --temp_po_left;
        }
    }
    for(i=0;i<n;++i)
    {
        int temp_po = i;
        while(sum_fall_right[temp_po] && temp_po <n)
        {
            int max_h = -1,ans=0,num = temp_po + sum_fall_right[temp_po];
            for(int j = temp_po;j<=num && j<n ;++j)
            {
                int temp = sum_fall_right[j] + (j-temp_po+1);
                if(temp > max_h)
                {
                    max_h = temp;
                    ans = j;
                }
            }
            if(temp_po == ans)
                temp_po = temp_po + sum_fall_right[temp_po];
            else
                temp_po = ans;
        }
        sum_all_right[i] = temp_po-i;
    }
    for(i=0;i<n;++i)
    {
        int temp_po = i;
        while(sum_fall_left[temp_po] && temp_po>=0)
        {
            int max_h = -1,ans=0,num = temp_po - sum_fall_left[temp_po];
            for(int j = temp_po;j>=num && j>=0;--j)
            {
                int temp = sum_fall_left[j]+(temp_po-j+1);
                if(temp > max_h)
                {
                    max_h = temp;
                    ans = j;
                }
            }
            if(temp_po == ans)
                temp_po = temp_po - sum_fall_left[temp_po];
            else
                temp_po = ans;
        }
        sum_all_left[i] = i - temp_po;
    }
    for(i=0; i<n; ++i)
    {
        if(sum_all_right[i] > max_right)
        {
            max_right = sum_all_right[i];
            ans_right = i;
        }
        if(sum_all_left[i] > max_left)
        {
            max_left = sum_all_left[i];
            ans_left = i;
        }
    }
    ++ans_right;
    ++ans_left;
    if(max_right > max_left)
        printf("%d R",ans_right);
    else if(max_left > max_right)
        printf("%d L",ans_left);
    else if(ans_right < ans_left)
        printf("%d R",ans_right);
    else
        printf("%d L",ans_left);
    return 0;
}
