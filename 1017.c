#include<stdio.h>
int main()
{
    int length,i,a;
    scanf("%d",&length);
    if(length>=1 && length <=10)
    {
        int num[length][length];
        int sumc[length];
        int sumr[length];
        for(i=0;i<length;i++)
        {
            sumc[i] =0;
            sumr[i] =0;
        }
        for(i=0;i<length;i++)
        {
            for(a=0;a<length;a++)
            {
                scanf("%d",&num[i][a]);
            }
        }
        for(i=0;i<length;i++)
        {
            for(a=0;a<length;a++)
            {
                sumc[i] = sumc[i] +num[i][a];
                sumr[i] = sumr[i] + num[a][i];
            }
        }
        int t1=0,t2=0;
        for(i=0;i<length;i++)
        {
            t1 = t1+num[i][i];
        }
        for(i=0,a=length-1;i<length;i++,a--)
        {
            t2 = t2+num[i][a];
        }
        int b,c2=0;
        for(i=0;i<length;i++)
        {
            for(a=0,b=a+1;a<length;a++)
            {
                if(num[i][a] == num[i][b])
                    if(b!=a)
                        c2++;
                    if(b!=length-1)
                       b++;
               }
           }
           int check=0,c1=0;
           for(i=0;i<length;i++)
           {
            for(a=0;a<length;a++)
            {
                if(num[i][a] > length*length)
                    c1++;
            }
        }
        if(c1==0 && length>=1 && length<=10 && c2==0)
        {
            for(i=0;i<length;i++)
            {
                if(sumr[i] != sumc[i] || t1!= t2)
                    check++;
            }
            if(check==0)
                printf("Yes");
            else if(check>0)
                printf("No");
        }
    }
    return 0;
}
