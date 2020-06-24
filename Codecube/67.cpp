#include <stdio.h>
#include <string.h>
int main()
{
    char str_1[1001];
    scanf("%s",&str_1);
    int i,j,k,n,count=0;
    int length = strlen(str_1);
    char str_2[length+1];
    strcpy(str_2,str_1);
    for(i=0;i<length;i++)
    {
        if(str_1[i] >= 97)
            str_1[i] = str_1[i]-32;
    }
    for(i=0;i<length;i++)
    {
        if( i<length-3 &&str_1[i] == 'S' && str_1[i+1] == 'I' &&str_1[i+2] == 'P' &&str_1[i+3] == 'A')
        {
            printf("%c%c%c%c%c%c",34,str_2[i],str_2[i+1],str_2[i+2],str_2[i+3],34);
            i+=3;
            count++;
        }
        else
            printf("%c",str_2[i]);
    }
    printf("\n%d",count);
    return 0;
}
