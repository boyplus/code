#include <stdio.h>
char str_1[1000001],str_2[1000001];
int main()
{
    scanf("%s %s",&str_1,&str_2);
    int i,count_2=0;
    for(i=0; str_1[i] != '\0'; i++)
    {
        if(str_1[i] >= 97)
            str_1[i] -= 32;
        if(str_2[i] >= 97)
            str_2[i] -= 32;
    }
    int key[i-1];
    for(i=0; str_1[i]!='\0'; i++)
    {
        while(str_1[i] != str_2[i])
        {
            str_1[i]--;
            count_2++;
            if(str_1[i] < 65)
                str_1[i] = 90;
        }
        if(count_2 < 10)
            key[i] = count_2;
        else
        {
            printf("R.I.P.");
            return 0;
        }
        count_2=0;
    }
    for(i=0; str_1[i]!='\0' ; i++)
        printf("%d",key[i]);
    return 0;
}
