#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char string[n][1001];
    int i,j,k;
    int top[n],front[n],left[n],back[n],right[n],bottom[n];
    for(i=0; i<n; i++)
    {
        top[i] = 1;
        front[i] = 2;
        left[i] = 3;
        back[i] = 5;
        right[i] = 4;
        bottom[i] = 6;
        scanf("%s",&string[i]);
        for(j=0; j<strlen(string[i]); j++)
        {
            if(string[i][j] == 'F')
            {
                if(top[i] ==1)
                {
                    top[i] = 5;
                }
                else if(top[i] == 5)
                {
                    top[i] = 6;
                }
                else if(top[i] == 6)
                {
                    top[i] = 2;
                }
                else if(top[i] == 2)
                {
                    top[i] = 1;
                }
                if(front[i]==2)
                {
                    front[i]=1;
                }
                else if(front[i] ==1)
                {
                    front[i] = 5;
                }
                else if(front[i] == 5)
                {
                    front[i] = 6;
                }
                else if(front[i] == 6)
                {
                    front[i] = 2;
                }
                if(back[i] == 5)
                {
                    back[i] = 6;
                }
                else if(back[i] == 6)
                {
                    back[i] =2;
                }
                else if(back[i] == 2)
                {
                    back[i] =1;
                }
                else if(back[i] ==1)
                {
                    back[i] =5;
                }
                if(bottom[i] == 6)
                {
                    bottom[i] = 2;
                }
                else if(bottom[i] == 2)
                {
                    bottom[i] = 1;
                }
                else if(bottom[i] == 1)
                {
                    bottom[i] = 5;
                }
                else if(bottom[i] == 5)
                {
                    bottom[i] = 6;
                }
            }
            if(string[i][j] == 'B')
            {
                //printf("in B\n");
                if(top[i] == 1)
                {
                    top[i] = 2;
                }
                else if(top[i] == 2)
                {
                    top[i] = 6;
                }
                else if(top[i] ==6)
                {
                    top[i] = 5;
                }
                else if(top[i] == 5)
                {
                    top[i] = 1;
                }
                if(front[i] == 2)
                {
                    front[i] = 6;
                }
                else if(front[i] == 6)
                {
                    front[i] = 5;
                }
                else if(front[i] == 5)
                {
                    front[i] = 1;
                }
                else if(front[i] == 1)
                {
                    front[i] = 2;
                }
                if(back[i] == 5)
                {
                    back[i] = 1;
                }
                else if(back[i] == 1)
                {
                    back[i] = 2;
                }
                else if(back[i] == 2)
                {
                    back[i] = 6;
                }
                else if(back[i] == 6)
                {
                    back[i] = 5;
                }
                if(bottom[i] == 6)
                {
                    bottom[i] = 5;
                }
                else if(bottom[i] == 5)
                {
                    bottom[i] = 1;
                }
                else if(bottom[i] == 1)
                {
                    bottom[i] = 2;
                }
                else if(bottom[i] ==2)
                {
                    bottom[i] = 6;
                }
            }
            if(string[i][j] == 'L')
            {
                if(top[i] == 1)
                {
                    top[i] = 4;
                }
                else if(top[i] == 4)
                {
                    top[i] = 6;
                }
                else if(top[i] == 6)
                {
                    top[i] = 3;
                }
                else if(top[i] == 3)
                {
                    top[i] = 1;
                }
                if(left[i] == 3)
                {
                    left[i] = 1;
                }
                else if(left[i] == 1)
                {
                    left[i] = 4;
                }
                else if(left[i] == 4)
                {
                    left[i] = 6;
                }
                else if(left[i] == 6)
                {
                    left[i] = 3;
                }
                if(right[i] == 4)
                {
                    right[i] = 6;
                }
                else if(right[i] == 6)
                {
                    right[i] = 3;
                }
                else if(right[i] == 3)
                {
                    right[i] = 1;
                }
                else if(right[i] == 1)
                {
                    right[i] = 4;
                }
                if(bottom[i] == 6)
                {
                    bottom[i] = 3;
                }
                else if(bottom[i] == 3)
                {
                    bottom[i] = 1;
                }
                else if(bottom[i] == 1)
                {
                    bottom[i] = 4;
                }
                else if(bottom[i] == 4)
                {
                    bottom[i] = 6;
                }
                else if(bottom[i] == 6)
                {
                    bottom[i] = 3;
                }
            }
            if(string[i][j] == 'R')
            {
                if(top[i] == 1)
                {
                    top[i] = 3;
                }
                else if(top[i] == 3)
                {
                    top[i] = 6;
                }
                else if(top[i] == 6)
                {
                    top[i] = 4;
                }
                else if(top[i] == 4)
                {
                    top[i] = 1;
                }
                if(left[i] == 3)
                {
                    left[i] = 6;
                }
                else if(left[i] == 6)
                {
                    left[i] = 4;
                }
                else if(left[i] == 4)
                {
                    left[i] = 1;
                }
                else if(left[i] == 1)
                {
                    left[i] =3;
                }
                if(right[i] == 4)
                {
                    right[i] = 1;
                }
                else if(right[i] == 1)
                {
                    right[i] = 3;
                }
                else if(right[i] == 3)
                {
                    right[i] = 6;
                }
                else if(right[i] = 6)
                {
                    right[i] = 4;
                }
                if(bottom[i] == 6)
                {
                    bottom[i] = 4;
                }
                else if(bottom[i] == 4)
                {
                    bottom[i] = 1;
                }
                else if(bottom[i] == 1)
                {
                    bottom[i] = 3;
                }
                else if(bottom[i]  == 3)
                {
                    bottom[i] = 6;
                }
            }
            if(string[i][j] == 'C')
            {
                if(front[i] == 2)
                {
                    front[i] =4;
                }
                else if(front[i] == 4)
                {
                    front[i] =5;
                }
                else if(front[i] == 5)
                {
                    front[i] = 3;
                }
                else if(front[i] == 3)
                {
                    front[i] = 2;
                }
                if(left[i] == 3)
                {
                    left[i] =2;
                }
                else if(left[i] == 2)
                {
                    left[i] = 4;
                }
                else if(left[i] == 4)
                {
                    left[i] = 5;
                }
                else if(left[i] == 5)
                {
                    left[i] = 3;
                }
                else if(left[i] == 3)
                {
                    left[i] = 2;
                }
                if(back[i] == 5)
                {
                    back[i] = 3;
                }
                else if(back[i] == 3)
                {
                    back[i] = 2;
                }
                else if(back[i] == 2)
                {
                    back[i] = 4;
                }
                else if(back[i] == 4)
                {
                    back[i] = 5;
                }
                if(right[i] == 4)
                {
                    right[i] = 5;
                }
                else if(right[i] == 5)
                {
                    right[i] = 3;
                }
                else if(right[i] == 3)
                {
                    right[i] = 2;
                }
                else if(right[i] == 2)
                {
                    right[i] = 4;
                }
            }
            if(string[i][j] == 'D')
            {
                if(front[i] == 2)
                {
                    front[i] =  3;
                }
                else if(front[i] == 3)
                {
                    front[i] = 5;
                }
                else if(front[i] == 5)
                {
                    front[i] = 4;
                }
                else if(front[i] == 4)
                {
                    front[i] = 2;
                }
                if(left[i] == 3)
                {
                    left[i] = 5;
                }
                else if(left[i] == 5)
                {
                    left[i] = 4;
                }
                else if(left[i] == 4)
                {
                    left[i] = 2;
                }
                else if(left[i] == 2)
                {
                    left[i] = 3;
                }
                if(back[i] == 5)
                {
                    back[i] = 4;
                }
                else if(back[i] == 4)
                {
                    back[i] = 2;
                }
                else if(back[i] == 2)
                {
                    back[i] = 3;
                }
                else if(back[i] == 3)
                {
                    back[i] =5;
                }
                if(right[i] == 4)
                {
                    right[i] = 2;
                }
                else if(right[i] == 2)
                {
                    right[i] = 3;
                }
                else if(right[i] == 3)
                {
                    right[i] = 5;
                }
                else if(right[i] == 5)
                {
                    right[i] = 4;
                }
            }
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d ",front[i]);
    }
    /*
    printf("top[i] = %d\n",top[i][i]);
    printf("front[i] = %d\n",front[i]);
    printf("left[i]t = %d\n",left[i]);
    printf("back[i] = %d\n",back[i]);
    printf("right[i] = %d\n",right[i]);
    printf("bottom[i] = %d\n",bottom[i]);
    */
    return 0;
}
/*
F = "หมุนมาทางด้านหน้า"
B = "หมุนไปทางด้านหลัง"
L = "หมุนไปทางซ้าย"
R = "หมุนไปทางขวา"
C = "หมุนตามเข็ม"
D = "หมุนทวนเข็ม"
*/
