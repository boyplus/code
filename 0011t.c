#include <stdio.h>
int main()
{
	int i,test[10],num[10],mod[10];
	int cont=10,a=0;
	for(i=0;i<10;i++)
	{
		//test[i] = 42;
		scanf("%d",&test[i]);
        num[i] = test[i];
        mod[i] = num[i]%42;
	}
    for(i=0;i<10;i++)
    {
        for(a=i+1;a<10;a++)
        {
            if(mod[i] == mod[a])
            {
                cont--;
                break;
            }
        }
    }
    printf("%d\n",cont);
	return 0;
}
