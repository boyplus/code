#include <cstdio>
#include <time.h>
#include <stdlib.h>
#include <math.h>
char str1[1000010],str2[1000010];
int def[200],num[200];
int main()
{
    srand(time(NULL));
	int i,j,len1,len2;
	long long count = 0;
	scanf("%d %d",&len1,&len2);
	scanf("%s %s",&str1,&str2);
	for(i=0;i<len2;++i)
		++def[str2[i]];
	for(i=0;i<len2;++i)
		++num[str1[i]];
    bool chk_first = true;
    for(i=97;i<=122;++i)
    {
        if(def[i] != num[i])
        {
            chk_first = false;
            break;
        }
    }
    if(chk_first)
    {
        bool chk = true;
        for(i=0;i<len2;++i)
        {
            if(str1[i] != str2[i])
            {
                chk = false;
                break;
            }
        }
        if(chk)
            ++count;
    }
	char temp = str1[0];
	int start = 1,end = len2+1;
	int between = end-start;
	int num_temp = sqrt(sqrt(len2))*2;
	for(i=len2;i<len1;++i)
	{
		bool chk = true;
		--num[temp];
		++num[str1[i]];
		for(j=97;j<=122;++j)
		{
			if(num[j] != def[j])
			{
				chk = false;
				break;
			}
		}
		if(chk)
		{
			bool chk2 = true;
			for(j=0;j<num_temp;++j)
            {
                int num_rand = rand()%between+start;
                int diff = num_rand - start;
                if(str1[num_rand] != str2[diff])
                {
                    chk2 = false;
                    break;
                }
            }
			if(chk2)
				++count;
		}
		temp = str1[start];
		++start;
		++end;
	}
	printf("%lld",count);
	return 0;
}

