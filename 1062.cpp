#include <stdio.h>
#include <string.h>
int main()
{
    int length_1,length_2,i,j,k;
    scanf("%d %d",&length_1,&length_2);
    char mom_1[length_1+1],mom_2[length_1+1];
    char string[length_2+1];
    scanf("%s %s",mom_1,mom_2);
    scanf("%s",string);
    char sort_[4]="";
    char temp;
    for(i=0;i<length_1;i++)
    {
        for(j=length_2-1;j>=0;j--)
        {
            sort_[0] = mom_1[i];
            sort_[2] = mom_2[i];
            sort_[1] = string[j];
            for(int k=0;k<3;k++)
            {
                for(int a=k+1;a<3;a++)
                {
                    if(sort_[k] >= sort_[a])
                    {
                        temp = sort_[k];
                        sort_[k] = sort_[a];
                        sort_[a] = temp;
                    }
                }
            }
            string[j] = sort_[1];
        }
    }
    printf("%s\n",string);
    return 0;
}
