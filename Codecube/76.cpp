#include <stdio.h>
#include <string.h>
int main()
{
    char str_1[14],str_2[14],result[14];
    scanf("%s %s %s",&str_1,&str_2,&result);
    int length_1 = strlen(str_1),i,j,k,n;
    int length_2 = strlen(str_2);
    char num_int_1[3]="00";
    char num_int_2[3] = "00";
    char sum_int[3]="00";
    int sum =0;
    int tod=0;
    for(i=0; i<length_1; i++)
        if(str_1[i] == '.')
            break;
    if(i==1)
        num_int_1[1] = str_1[0];
    else
    {
        num_int_1[0] = str_1[0];
        num_int_1[1] = str_1[1];
    }
    for(i=0; i<length_2; i++)
        if(str_2[i] == '.')
            break;
    if(i==1)
        num_int_2[1] = str_2[0];
    else
    {
        num_int_2[0] = str_2[0];
        num_int_2[1] = str_2[1];
    }
    char tod_1[11]="0000000000";
    char tod_2[11] = "0000000000";
    char sum_tod[11] = "0000000000";
    int count=0;
    for(i=0; i<length_1; i++)
    {
        if(str_1[i] == '.')
            count=i;
    }
    k=0;
    for(i=count+1; i<length_1; i++)
    {
        tod_1[k] = str_1[i];
        k++;
    }
    for(i=0; i<length_2; i++)
    {
        if(str_2[i] == '.')
            count=i;
    }
    k=0;
    for(i=count+1; i<length_2; i++)
    {
        tod_2[k] = str_2[i];
        k++;
    }
    for(i=9; i>=0; i--)
    {
        sum = ((tod_1[i]-48)+(tod_2[i]-48)+tod);
        sum_tod[i] = (sum%10)+48;
        if(sum > 9)
        {
            tod = 1;
        }
        else
            tod=0;
        sum =0;
    }
    for(i=1; i>=0; i--)
    {
        sum = ((num_int_1[i]-48)+(num_int_2[i]-48)+tod);
        sum_int[i] = (sum%10)+48;
        if(sum > 9)
        {
            tod = 1;
        }
        else
            tod=0;
        sum =0;
    }
    int length_3 = strlen(result);
    char num_int_result[3]="00";
    char num_tod_result[11]="0000000000";
    for(i=0; i<length_3; i++)
    {
        if(result[i] == '.')
            break;
    }
    if(i==1)
        num_int_result[1] = result[0];
    else
    {
        num_int_result[0] = result[0];
        num_int_result[1] = result[1];
    }
    for(i=0; i<length_3; i++)
    {
        if(result[i] == '.')
            break;
    }
    k=0;
    for(j=i+1; j<length_3; j++)
    {
        num_tod_result[k] = result[j];
        k++;
    }
    if(strcmp(num_int_result,sum_int) ==0 && strcmp(num_tod_result,sum_tod)==0)
        printf("Correct");
    else
        printf("Wrong");
    return 0;
}
