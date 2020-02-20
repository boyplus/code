#include <stdio.h>
int table_roi[10]={0},table_sib[10]={0},table_hnui[10]={0};
int num_re1[100]={0},num_re2[100]={0},num_re3[100]={0},num_re4[1000]={0};
long long sum_roi=0,sum_sib=0,sum_hnui=0;
long long sum_re1=0,sum_re2=0,sum_re3=0,sum_re4=0;
long long get_sum(long long);
void count_roi(char*);
void count_sib(char*);
void count_hnui(char*);
void re_1(char*);
void re_2(char*);
void re_3(char*);
void re_4(char*);
void print();
int main()
{
    char str[100];
    int i,j,k,m,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        count_roi(str);
        count_sib(str);
        count_hnui(str);
        re_1(str);
        re_2(str);
        re_3(str);
        re_4(str);
    }
    for(i=0;i<10;i++)
    {
        if(table_roi[i]>1)
            sum_roi = sum_roi+get_sum(table_roi[i]);
        if(table_sib[i]>1)
            sum_sib = sum_sib + get_sum(table_sib[i]);
        if(table_hnui[i]>1)
            sum_hnui = sum_hnui + get_sum(table_hnui[i]);
    }
    for(i=0;i<100;i++)
    {
        if(num_re1[i]>1)
            sum_re1 = sum_re1 + get_sum(num_re1[i]);
        if(num_re2[i]>1)
            sum_re2 = sum_re2 + get_sum(num_re2[i]);
        if(num_re3[i]>1)
            sum_re3 = sum_re3 + get_sum(num_re3[i]);
    }
    for(i=0;i<1000;i++)
    {
        if(num_re4[i]>1)
            sum_re4 = sum_re4 + get_sum(num_re4[i]);
    }
    long long sum_all=0;
    sum_all = sum_all+sum_roi+sum_sib+sum_hnui;
    sum_all = sum_all - sum_re1 - sum_re2 - sum_re3;
    sum_all = sum_all+sum_re4;
    printf("%lld\n",sum_all);
    return 0;
}
long long get_sum(long long num)
{
    long long sum=0;
    num--;
    while(num>=1)
    {
        sum = sum+num;
        num--;
    }
    return sum;
}
void re_1(char* str)
{
    num_re1[((str[0]-48)*10)+((str[1]-48))]++;
}
void re_2(char* str)
{
    num_re2[((str[1]-48)*10)+((str[2]-48))]++;
}
void re_3(char* str)
{
    num_re3[((str[0]-48)*10)+((str[2]-48))]++;
}
void re_4(char* str)
{
    num_re4[((str[0]-48)*100)+((str[1]-48)*10)+((str[2]-48))]++;
}
void count_roi(char* str)
{
    table_roi[str[0]-48]++;
}
void count_sib(char* str)
{
    table_sib[str[1]-48]++;
}
void count_hnui(char* str)
{
    table_hnui[str[2]-48]++;
}
