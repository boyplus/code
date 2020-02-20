#include <stdio.h>
#include<math.h>
int main()
{
    int n1,n2,n3;
    int m1,m2;
    scanf("%d %d %d",&n1,&n2,&n3);
    if(n1>0 && n1<100 && n2 >0 && n2 <100 && n3>0 && n3 <100)
    {
        m1= (n3-n2)-1;
        m2 = (n2-n1)-1;
        if(m1 >m2)
        {
            printf("%d\n",m1);
        }
        else
        {
            printf("%d\n",m2);
        }

    }
    return 0;
}
