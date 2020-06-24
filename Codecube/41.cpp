#include <cstdio>
int num[1000010];
int main()
{
    int i,j,n,k;
    long long count_all=0,sum = 0,max=-1;
    scanf("%d %d",&n,&k);
    bool have = false;
    for(i=0; i<n; i++)
    {
        scanf("%d",&num[i]);
        if(num[i] > max)
            max = num[i];
    }
    int start = max;
    bool chk_all = false;
    int ans=0;
    while(true)
    {
        int energy=0,count=0,index=0;
        bool chk = false;
        for(i=0; i<n; ++i)
        {
            if(energy < num[i])
            {
                energy = start;
                count++;
            }
            if(energy < num[i])
            {
                chk = true;
                break;
            }
            energy-=num[i];
        }
        if(count == k && chk == false)
        {
            have = true;
            ans = start;
            break;
        }
        else
        {
            chk = true;
        }
        if(have && chk)
        {
            break;
        }
        ++start;
    }
    //printf("start = %d\n",start);
    int temp = ans,last = ans;
    bool up = true;
    int ans_last = 0;
    int last_temp = temp;
    while(true)
    {
        //printf("temp = %d\n",temp);
        if(temp == 0)
        {
            //printf("temp = %d\n",temp);
            break;
        }
        if(up)
        {
            //printf("in up\n");
            last = last + temp;
            //check
            int energy=0,count=0,index=0;
            bool chk = false;
            for(i=0; i<n; ++i)
            {
                if(energy < num[i])
                {
                    energy = last;
                    count++;
                }
                if(energy < num[i])
                {
                    chk = true;
                    break;
                }
                energy-=num[i];
            }
            if(count == k && chk == false)
            {
                //printf("can use %d\n",last);
                up = true;
            }
            else
            {
                //printf("can't use %d\n",last);
                up = false;
                temp = temp/2;
            }
        }
        else
        {
            //printf("in down\n");
            last = last - temp;
            //check
            int energy=0,count=0,index=0;
            bool chk = false;
            for(i=0; i<n; ++i)
            {
                if(energy < num[i])
                {
                    energy = last;
                    count++;
                }
                if(energy < num[i])
                {
                    chk = true;
                    break;
                }
                energy-=num[i];
            }
            if(count == k && chk == false)
            {
                //printf("can use %d\n",last);
                temp = temp/2;
                up = true;
            }
            else
            {
                //printf("can't use %d\n",last);
                up = false;
                temp = temp/2;
            }
            
        }
    }
    //printf("last = %d\n",last);
    printf("%d\n",last-start);
    return 0;
}
