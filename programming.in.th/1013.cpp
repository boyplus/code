#include <stdio.h>
#include <string.h>
int find_min(char*);
bool count_str(int,char*,char);
char p[1000];
char str[1000];
int main()
{
    bool chk = false;
    int i,j,k,m,n;
    scanf("%s",&p);
    strcpy(str,p);
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        bool chk_2 = false;
        int question[10000]= {0};
        int count=0;
        int count_q=0;
        strcpy(str,p);
        while(1)
        {
            scanf("%d",&question[count_q]);
            count_q++;
            if(question[count_q-1]==0)
                break;
            char my_sign[] = {'+','*','^',')'};
            int my_min = find_min(str);
            chk = count_str(question[count_q-1],str,my_sign[my_min-1]);
            if(chk==false)
                chk_2 = true;
        }
        for(j=count_q-2; j>=0; j--)
            printf("op(%d,",question[j]);
        printf("p");
        for(j=1; j<count_q; j++)
            printf(")");
        printf("=");
        if(chk_2==true)
            printf("null\n");
        else if(chk==true)
            printf("%s\n",str);

    }
    return 0;
}
bool count_str(int question,char* str,char sign)
{
    int length = strlen(str),start=0,count_sign_2=0,cc=0,count_sign=0;
    int count_open=0,count_close=0,cc_2=0;
    for(int i=0;i<length;i++)
    {
        if(str[i]=='(')
            cc_2++;
        if((str[i]=='+'||str[i]=='^'||str[i]=='*')&&cc_2==0)
            count_sign_2++;
        if(str[i]==')')
            cc_2--;
    }
    if(strlen(str)==1&&question==1)
    {
        str[1] = '\0';
        return true;
    }
    if(strlen(str)==1&&question!=1)
        return false;
    bool chk = false;
    int end = length-1,i,j,k,n,m,count=0;
    char str_temp[1000];
    strcpy(str_temp,str);
    if(str[start]=='('&&str[end]==')'&&count_sign_2==0)
    {
        start++;
        end--;
        count++;
        if(count==question)
            chk = true;
    }
    else
    {
        for(i=0; i<length; i++)
        {
            if(str[i]=='(')
                cc++;
            if(str[i]==sign&&cc==0)
            {
                count_sign++;
                count++;
                if(count==question)
                {
                    chk = true;
                    end = i-1;
                    break;
                }
                chk = true;
                start = i+1;
            }
            if(str[i]==')')
                cc--;
        }
    }
    if(chk == false||count_sign<question-1)
        return false;
    strcpy(str,"");
    int last = (end-start)+1;
    for(i=0; i<last; i++)
    {
        str[i] = str_temp[start];
        start++;
    }
    str[last] = '\0';
    return true;
}
int find_min(char *str)
{
    int cc=0;
    int length = strlen(str),num[1000]= {0},min=10;
    for(int i=0; i<length; i++)
    {
        if(str[i]=='+'&&cc==0)
            num[i]=1;
        if(str[i]=='*'&&cc==0)
            num[i]=2;
        if(str[i]=='^'&&cc==0)
            num[i]=3;
        if(str[i]=='(')
        {
            num[i]=4;
            cc++;
        }
        if(str[i]==')')
        {
            num[i]=4;
            cc--;
        }
        if(num[i]<min&&num[i]!=0)
            min = num[i];
    }
    return min;
}
