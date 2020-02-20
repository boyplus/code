#include <stdio.h>
#include <string.h>
#include <math.h>
char string[100001];
bool check_num(int);
int bracket_1_open = 0; //(
int bracket_1_close =0;  //)
int bracket_2_open = 0; //[
int bracket_2_close=0;  //]
int bracket_3_open =0;  //{
int bracket_3_close=0;  //}
int main()
{
    int i=0,j=0,k=0,n=0,x=0,y=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%s",&string);
        bool check_1 = true;
        int length = strlen(string);
        check_1 = check_num(length);
        if(check_1 == false)
        {
            printf("no in num\n");
        }
        if(check_1 == true)
        {
            bool check_2 = true;
            //check_2 = check_br(0,length);
            if(check_2 == true)
            {
                printf("yes in check_br\n");
            }
            if(check_2 == false)
            {
                printf("no in check_br\n");
            }
        }
        bracket_1_open=0;
        bracket_1_close=0;
        bracket_2_open=0;
        bracket_2_close=0;
        bracket_3_open=0;
        bracket_3_close=0;
    }
    return 0;
}
bool check_num(int last)
{
    for(int i=0; i<last; i++)
    {
        if(string[i] == '(')
        {
            bracket_1_open++;
        }
        else if(string[i] == ')')
        {
            bracket_1_close++;
        }
        else if(string[i] == '[')
        {
            bracket_2_open++;
        }
        else if(string[i] == ']')
        {
            bracket_2_close++;
        }
        else if(string[i] == '{')
        {
            bracket_3_open++;
        }
        else if(string[i] == '}')
        {
            bracket_3_close++;
        }
    }
    if(bracket_1_open!=bracket_1_close || bracket_2_open!=bracket_2_close || bracket_3_open!=bracket_3_close)
    {
        return false;
    }
    else
    {
        return true;
    }
}

