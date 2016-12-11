#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char num1[101]="";
    char num2[101]="";
    char result[300]="";
    char operand;
    scanf("%s",&num1);
    scanf(" %c",&operand);
    scanf("%s",&num2);
    int length_1 = strlen(num1);
    int length_2 = strlen(num2);
    int i,j,k=0,n=0;
    if(operand == '+')
    {
        if(length_1 < length_2)
        {
            char temp[length_2];
            strcpy(temp,num2);
            strcpy(num2,num1);
            strcpy(num1,temp);
            int temp_length = length_1;
            length_1 = length_2;
            length_2 = temp_length;
        }
        for(i=length_1-length_2;i<length_1;i++)
        {
            if(num1[i] == '0')
            {
                if(num2[k] == '0')
                {
                    result[i] = '0';
                }
                if(num2[k] == '1')
                {
                    result[i] = '1';
                }
            }
            k++;
        }
        for(i=0;i<length_1-length_2;i++)
        {
            result[i] = num1[i];
        }
        if(length_1 == length_2)
        {
            result[0] = '2';
            for(i=1;i<length_1;i++)
            {
                result[i] = '0';
            }
        }
    }
    if(operand == '*')
    {
        result[0] = '1';
        int sum = length_1+length_2;
        for(i=1;i<sum-1;i++)
        {
            result[i] = '0';
        }
    }
    printf("%s\n",result);
    return 0;
}
