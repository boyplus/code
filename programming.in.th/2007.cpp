#include <cstdio>
char str_find[3001],str[3000001];
int table_1[60],table_2[60];
int main()
{
    int i,j,k,n1,n2,m,count=1,sum=0;
    scanf("%d %d",&n1,&n2);
    scanf("%s %s",&str_find,&str);
    for(i=0; i<n1; ++i)
        ++table_1[str_find[i]-65];
    for(i=0; i<n1; ++i)
        ++table_2[str[i]-65];
    int position_1 = str[0]-65;
    bool chk = true;
    for(i=0; i<=57; ++i)
    {
        if(table_2[i]!=table_1[i])
        {
            chk = false;
            break;
        }
    }
    if(chk)
        ++sum;
    for(i=n1; i<n2; ++i)
    {
        bool chk = true;
        --table_2[position_1];
        ++table_2[str[i]-65];
        for(j=0; j<=57; ++j)
        {
            if(table_2[j]!=table_1[j])
            {
                chk = false;
                break;
            }
        }
        if(chk)
            ++sum;
        position_1 = str[count]-65;
        ++count;
    }
    printf("%d\n",sum);
    return 0;
}
