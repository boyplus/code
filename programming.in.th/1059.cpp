#include <stdio.h>
#include <string.h>
#include <math.h>
char string[8][5] = {"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};
char message[1000]="";
int now_button=0;
int click =0,length=0;
void check_string(int);
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    int count=0;
    int button_start;
    int click_start;
    scanf("%d %d",&button_start,&click_start);
    now_button = button_start;
    click = click_start;
    if(now_button == 1)
    {
        while(click >=1)
        {
            if(length > 0 )
            {
                length--;
                message[length] = '\0';
            }
            click--;
        }
    }
    else
        check_string(now_button-2);
    int h,v;
    for(i=0; i<n-1; i++)
    {
        scanf("%d %d %d",&h,&v,&click);
        if(h>=1)
            now_button = now_button+h;
        if(h<=-1)
            now_button = now_button-fabs(h);
        if(v >=1)
            now_button = now_button+(3*fabs(v));
        if(v <= -1)
            now_button = now_button-(3*fabs(v));
        if(now_button == 1)
        {
            while(click >=1)
            {
                if(length > 0 )
                {
                    length--;
                    message[length] = '\0';
                }
                click--;
            }
        }
        else
            check_string(now_button-2);
    }
    if(length!=0)
        printf("%s\n",message);
    else
        printf("null\n");
    return 0;
}
void check_string(int button)
{
    int count_1 =0;
    for(int j=0; j<click; j++)
    {
        if(count_1 > strlen(string[button])-1)
            count_1 =0;
        if(j == click-1)
        {
            message[length] = string[button][count_1];
        }
        count_1++;
    }
    length++;
}
