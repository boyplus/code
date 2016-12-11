#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d",&n);
    char string[1001];
    int i,j,k;
    int front=2;
    int count =0;
    for(i=0;i<n;i++)
    {
        scanf("%s",string);
        int length = strlen(string);
        for(j=0;j<length;j++)
        {
            if(string[j] == 'F')
            {
                if(front == 2)
                {
                    front = 1;
                }
                else if(front == 1)
                {
                    front = 5;
                }
                else if(front == 5)
                {
                    front = 4;
                }
                else if(front ==  6)
                {
                    front =2;
                }
            }
            else if(string[j] == 'B')
            {
                if(front == 2)
                {
                    front = 6;
                }
                else if(front == 6)
                {
                    front =5;
                }
                else if(front == 5)
                {
                    front = 1;
                }
                else if(front == 1)
                {
                    front = 2;
                }
            }
            else if(string[j] == 'C')
            {
                if(front == 2)
                {
                    front = 4;
                }
                else if(front == 4)
                {
                    front = 5;
                }
                else if(front == 5)
                {
                    front = 3;
                }
                else if(front == 3)
                {
                    front = 2;
                }
            }
            else if(string[j] == 'D')
            {
                if(front == 2)
                {
                    front = 3;
                }
                else if(front == 3)
                {
                    front = 5;
                }
                else if(front == 5)
                {
                    front = 4;
                }
                else if(front == 4)
                {
                    front = 2;
                }
            }
        }
        printf("%d ",front);
        front = 2;
    }
    return 0;
}
/*
F = "หมุนมาทางด้านหน้า"
B = "หมุนไปทางด้านหลัง"
L = "หมุนไปทางซ้าย"
R = "หมุนไปทางขวา"
C = "หมุนทวนเข็ม"
D = "หมุนตามเข็ม"
*/
