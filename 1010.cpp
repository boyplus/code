#include <stdio.h>
#include <iostream>
#include <string.h>
char string1[25][25];
char string_find[100][16];
int ans_m[100];
int ans_n[100];
int temp_j = 0,temp_x = 0;
int temp_ans_j = 0,temp_ans_x = 0;
int count=1;
void change_start(int,int);
void change_find(int,int);
using namespace std;
int main()
{
    int i,j,k,n,m;
    scanf("%d %d",&m,&n);
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf(" %c",&string1[i][j]);
    int n_find;
    scanf("%d",&n_find);
    for(i=0; i<n_find; i++)
    {
        scanf("%s",string_find[i]);
        change_find(strlen(string_find[i]),i);
    }
    change_start(m,n);
    for(i=0; i<n_find; i++)
    {
        bool check = false;
        int length_now = strlen(string_find[i]);
        for(j=0; j<m; j++)
        {
            for(int x=0; x<n; x++)
            {
                if(string_find[i][0] == string1[j][x])
                {
                    temp_j = j;
                    temp_x = x+1;
                    temp_ans_j = j;
                    temp_ans_x = x;
                    count=1;
                    for(int a=1; a<length_now &&temp_x < n; a++)
                    {
                        if(string_find[i][a] == string1[j][temp_x])
                            count++;
                        temp_x++;
                    }
                    if(count >= length_now)
                    {
                        ans_m[i] = temp_ans_j;
                        ans_n[i] = temp_ans_x;
                        check = true;
                        break;
                    }
                    count = 1;
                    temp_j = j+1;
                    temp_x = x;
                    for(int a=1; a<length_now && temp_j < m; a++)
                    {
                        if(string_find[i][a] == string1[temp_j][temp_x])
                            count++;
                        temp_j++;
                    }
                    if(count >= length_now)
                    {
                        ans_m[i] = temp_ans_j;
                        ans_n[i] = temp_ans_x;
                        check = true;
                        break;
                    }
                    count = 1;
                    temp_j = j;
                    temp_x = x-1;
                    for(int a=1; a<length_now && temp_x >= 0 ; a++)
                    {
                        if(string_find[i][a] == string1[temp_j][temp_x])
                            count++;
                        temp_x--;
                    }
                    if(count >= length_now)
                    {
                        ans_m[i] = temp_ans_j;
                        ans_n[i] = temp_ans_x;
                        check = true;
                        break;
                    }
                    count = 1;
                    temp_j = j-1;
                    temp_x = x;
                    for(int a=1; a<length_now && temp_j >= 0; a++)
                    {
                        if(string_find[i][a] == string1[temp_j][temp_x])
                            count++;
                        temp_j--;
                    }
                    if(count >= length_now)
                    {
                        ans_m[i] = temp_ans_j;
                        ans_n[i] = temp_ans_x;
                        check = true;
                        break;
                    }
                    count = 1;
                    temp_j = j-1;
                    temp_x = x+1;
                    for(int a = 1; a<length_now && temp_x < n && temp_j >=0  ; a++)
                    {
                        if(string_find[i][a] == string1[temp_j][temp_x])
                            count++;
                        temp_x++;
                        temp_j--;
                    }
                    if(count >= length_now)
                    {
                        ans_m[i] = temp_ans_j;
                        ans_n[i] = temp_ans_x;
                        check = true;
                        break;
                    }
                    count = 1;
                    temp_j = j+1;
                    temp_x = x+1;
                    for(int a=1; a<length_now && temp_j <m && temp_x <n ; a++)
                    {
                        if(string_find[i][a] == string1[temp_j][temp_x])
                            count++;
                        temp_x++;
                        temp_j++;
                    }
                    if(count >= length_now)
                    {
                        ans_m[i] = temp_ans_j;
                        ans_n[i] = temp_ans_x;
                        check = true;
                        break;
                    }
                    count = 1;
                    temp_j = j+1;
                    temp_x = x-1;
                    for(int a=1; a<length_now && temp_x >=0 && temp_j < m; a++)
                    {
                        if(string_find[i][a] == string1[temp_j][temp_x])
                            count++;
                        temp_x--;
                        temp_j++;
                    }
                    if(count >= length_now)
                    {
                        ans_m[i] = temp_ans_j;
                        ans_n[i] = temp_ans_x;
                        check = true;
                        break;
                    }
                    count = 1;
                    temp_j = j-1;
                    temp_x = x-1;
                    for(int a=1; a<length_now; a++)
                    {
                        if(string_find[i][a] == string1[temp_j][temp_x])
                            count++;
                        temp_j--;
                        temp_x--;
                    }
                    if(count >= length_now)
                    {
                        ans_m[i] = temp_ans_j;
                        ans_n[i] = temp_ans_x;
                        check = true;
                        break;
                    }
                }
            }
            if(check == true)
                break;
        }
    }
    for(i=0; i<n_find; i++)
        printf("%d %d\n",ans_m[i],ans_n[i]);
    return 0;
}
void change_start(int m,int n)
{
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            if(string1[i][j] >= 97)
                string1[i][j]-=32;
}
void change_find(int length,int position)
{
    for(int i=0; i<length; i++)
        if(string_find[position][i] >= 97)
            string_find[position][i]-=32;
}
