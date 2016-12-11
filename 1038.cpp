#include <cstdio>
#include <limits.h>
bool save_row[20] = {false},save_col[20] = {false};
int data[20][20],n;
float max = -99999999.00;
void make(int,float);
int main()
{
    int i,j,k,m;
    scanf("%d",&n);
    for(i=0; i<n; ++i)
    {
        for(j=0; j<n; ++j)
        {
            scanf("%d",&data[i][j]);
        }
    }
    make(0,1);
    printf("%f\n",max*100.00);
    return 0;
}
void make(int count,float pay)
{
    if(count == n)
    {
        //printf("pay = %f\n",pay);
        if(pay > max)
            max = pay;
    }
    else
    {
        for(int i=0; i<n; ++i)
        {
            if(save_row[i] == false)
            {
                save_row[i] = true;
                for(int j=0; j<n; ++j)
                {
                    if(save_col[j] == false)
                    {
                        save_col[j] = true;
                        make(count+1,data[i][j]/100.00*pay);
                        save_col[j] = false;
                    }
                }
                save_row[i] = false;
            }
        }
    }
}
