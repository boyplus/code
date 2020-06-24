#include <cstdio>
int main()
{
	bool ban[10] = {false};
	char str[20];
	int i,j,n,temp,mm=0,ss=0,ms=0,now_mm=0,now_ss=0,now_ms=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		ban[temp] = true;
	}
	scanf("%s",&str);
	mm = ((str[0]-48)*10) + ((str[1]-48));
	ss = ((str[3]-48)*10) + ((str[4]-48));
	ms = ((str[6]-48)*10) + ((str[7]-48));
	printf("%d %d %d",mm,ss,ms);
	while(now_mm != mm || now_ss != ss || now_ms != ms)
	{
		if(ban[now_ms%10] || ban[now_ms/10])
		{
			now_ms++;
			if(now_ms >= 100)
			{
				now_ms = 0;
				now_ss++;
				if(now_ss >= 60)
				{
					now_ss = 0;
					now_mm++;
				}
			}
		}
	}
	return 0;
}
