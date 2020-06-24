#include <stdio.h>
#include <string.h>
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    char str[21];
    for(i=0;i<n;i++)
    {
        scanf("%s",&str);
        int length = strlen(str);
        bool time_out = false;
        bool wrong = false;
        bool yes = false;
        bool run_error = false;
        for(j=0;j<length;j++)
        {
            if(str[j] == 'X')
            {
                run_error = true;
            }
            if(str[j] == 'T')
            {
                time_out = true;
            }
            if(str[j] == '-')
            {
                wrong = true;
            }
        }
        if(run_error == true)
        {
            printf("Case #%d: No - Runtime error\n",i+1);
        }
        else if(time_out == true)
        {
            printf("Case #%d: No - Time limit exceeded\n",i+1);
        }
        else if(wrong == true)
        {
            printf("Case #%d: No - Wrong answer\n",i+1);
        }
        else
        {
            printf("Case #%d: Yes\n",i+1);
        }
    }
    return 0;
}
