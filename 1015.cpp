#include <stdio.h>
int n,num[17][17];
bool ch1=false,ch2=false,ch3=false,ch4=false,ch5=false,ch6=false,ch7=false,ch8=false;
void print();
void reset();
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&num[i][j]);
    int count=0;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(num[i][j] == num[i][j+1] && num[i][j] == num[i+1][j] && num[i][j]!=0 && num[i][j] != num[i+1][j+1] && j < n-1 && i< n-1)
            {
                if(i > 0 && num[i][j] == num[i-1][j])
                    ch1 = true;
                if(i > 0 && num[i][j] == num[i-1][j+1])
                    ch2 = true;
                if(j > 0 && num[i][j] == num[i][j-1])
                    ch3 = true;
                if(j > 0 && num[i][j] == num[i+1][j-1])
                    ch4 = true;
                if(i < n-2 && num[i][j] == num[i+2][j])
                    ch5 = true;
                if(num[i][j] == num[i+1][j+1])
                    ch6 = true;
                if(j < n-2 && num[i][j] == num[i][j+2])
                    ch7 = true;
                if(ch1 == false && ch2 == false && ch3 == false && ch4 == false && ch5 == false && ch6 == false && ch7 == false)
                {
                    count++;
                    num[i][j] = 0;
                    num[i][j+1] = 0;
                    num[i+1][j] = 0;
                }
            }
            reset();
            if(num[i][j] == num[i+1][j] && num[i][j] == num[i+1][j-1] && j >0 && i < n-1&& num[i][j] != 0)
            {
                if(i>0 && num[i][j] == num[i-1][j])
                    ch1 = true;
                if(num[i][j] == num[i][j-1])
                    ch2 = true;
                if(j < n-1 && num[i][j] == num[i][j+1])
                    ch3 = true;
                if(j<n-1 && num[i][j] == num[i+1][j+1])
                    ch4 = true;
                if(i < n-2 && num[i][j] == num[i+2][j])
                    ch5 = true;
                if(i < n-2 && num[i][j] == num[i+2][j-1])
                    ch6 = true;
                if(j > 1 && num[i][j] == num[i+1][j-2])
                    ch7 = true;
                if(ch1 == false && ch2 == false && ch3 == false && ch4 == false && ch5 == false && ch6 == false && ch7 == false)
                {
                    count++;
                    num[i][j] = 0;
                    num[i+1][j] = 0;
                    num[i+1][j-1] = 0;
                }
            }
            reset();
            if(num[i][j] == num[i][j+1] && num[i][j] == num[i+1][j+1] && i< n-1 && j < n-1 && num[i][j]!=0)
            {
                if(num[i][j] == num[i+1][j])
                    ch1 = true;
                if(i >0 && num[i][j] == num[i-1][j])
                    ch2 = true;
                if(i>0 && num[i][j] == num[i-1][j+1])
                    ch3 = true;
                if(j >0 && num[i][j] == num[i][j-1])
                    ch4 = true;
                if(j < n-2 && num[i][j] == num[i][j+2])
                    ch5 = true;
                if(j < n-2 && num[i][j] == num[i+1][j+2])
                    ch6 = true;
                if(i < n-2 && num[i][j] == num[i+2][j+1])
                    ch7 = true;
                if(ch1 == false && ch2 == false && ch3 == false && ch4 == false && ch5 == false && ch6 == false && ch7 == false)
                {
                    count++;
                    num[i][j] =0;
                    num[i][j+1] =0;
                    num[i+1][j+1] =0;
                }
            }
            reset();
            if(num[i][j] == num[i+1][j] && num[i][j] == num[i+1][j+1] && i < n-1 && j <n-1)
            {
                if(i > 0 && num[i][j] == num[i-1][j])
                   ch1 = true;
                if(j >0 && num[i][j] == num[i][j-1])
                    ch2 = true;
                if(num[i][j] == num[i][j+1])
                    ch3= true;
                if(j >0 && num[i][j] == num[i+1][j-1])
                    ch4 = true;
                if(j < n-2 && num[i][j] == num[i+1][j+2])
                    ch5 = true;
                if(i< n-2 && num[i][j] == num[i+2][j])
                    ch6 = true;
                if(i < n-2 && num[i][j] == num[i+2][j+1])
                    ch7 = true;
                if(ch1 == false && ch2 == false && ch3 == false && ch4 == false && ch5 == false && ch6 == false && ch7 == false)
                {
                    count++;
                    num[i][j] = 0;
                    num[i+1][j] =0;
                    num[i+1][j+1] =0;
                }
            }
            reset();
        }
    }
    printf("%d\n",count);
    return 0;
}
void reset()
{
    ch1=false;
    ch2=false;
    ch3=false;
    ch4=false;
    ch5=false;
    ch6=false;
    ch7=false;
    ch8=false;
}
