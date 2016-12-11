#include <stdio.h>
#include <string.h>
void change_string();
bool check_palindrome();
bool check_double_palindrome();
char string[300]="";
int length =0;
int main()
{
    int i,j,k;
    scanf("%s",string);
    length = strlen(string);
    change_string();
    bool stat = check_palindrome();
    if(length == 1)
    {
        printf("Double Palindrome");
        return 0;
    }
    if(stat == true)
    {
        bool stat_2 = check_double_palindrome();
        if(stat_2 == true)
            printf("Double Palindrome\n");
        else
             printf("Palindrome\n");
    }
    else
        printf("No\n");
    return 0;
}
void change_string()
{
    for(int i=0; i<length; i++)
        if(string[i] >= 97)
            string[i] = string[i]-32;
}
bool check_palindrome()
{
    int end = 0;
    int j = length-1;
    int count=0;
    if(length%2==0)
        end = length/2;
    else
        end = length/2+1;
    for(int i=0; i<end; i++)
    {
        if(string[i] == string[j])
        {
            count++;
        }
        j--;
    }
    if(count >= end)
        return true;
    else
        return false;
}
bool check_double_palindrome()
{
    int count=0;
    int end = 0;
    int j=0;
    if(length%2==0)
        end = length/4;
    else
    {
        end = length/4+1;
    }
    j = length/2-1;
    for(int i=0;i<end;i++)
    {
        if(string[i] == string[j])
        {
            count++;
        }
        j--;
    }
    if(count >= end)
        return true;
    else
        return false;
}
