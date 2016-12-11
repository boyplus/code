#include <stdio.h>
#include <string.h>
//#include <conio.h>
#include <iostream>
#include <vector>
using namespace std;
char string1[1000][1000];
int L[3000],H[3000],R[3000];
int temp_L=0,temp_H=0,temp_R=0;
int max_high=-1,max_long=-1;
int this_x=0,this_y=0;
vector<int> my_ans;
void find_right_from_down();
void find_up();
void find_down();
void find_right();
void print1();
void print2();
int main()
{
    int i,j,k,n;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d %d %d",&L[i],&H[i],&R[i]);
        if(H[i] > max_high)
        {
            max_high = H[i];
        }
        if(R[i] > max_long)
        {
            max_long = R[i];
        }
    }
    for(i=0; i<max_high; i++)
    {
        for(j=0; j<=max_long; j++)
        {
            string1[i][j] = ' ';
        }
    }
    //printf("max high = %d\n",max_high);
    //printf("max long = %d\n",max_long);
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(L[i] > L[j])
            {
                temp_L = L[i];
                L[i] = L[j];
                L[j] = temp_L;
                temp_H = H[i];
                H[i] = H[j];
                H[j] = temp_H;
                temp_R = R[i];
                R[i] = R[j];
                R[j] = temp_R;
            }
        }
    }
    int start=0;
    int count_1=0;
    for(i=0; i<n; i++)
    {
        j = L[i];
        //in up
        for(start=0; start<H[i]; start++)
        {
            if(string1[start][j] == ' ')
            {
                string1[start][j] = '*';
            }
            else if(string1[start][j] == '*')
            {
                string1[start][j] = '+';
            }
        }
        //in right
        start--;
        j++;
        for(j=j; j<=R[i]; j++)
        {
            if(string1[start][j] == ' ')
            {
                string1[start][j] = '*';
            }
            else if(string1[start][j] == '*')
            {
                string1[start][j] = '+';
            }
        }
        //in down
        j--;
        start--;
        for(start=start; start>=0; start--)
        {
            if(string1[start][j] == ' ')
            {
                string1[start][j] = '*';
            }
            else if(string1[start][j] == '*')
            {
                string1[start][j] = '+';
            }
        }
    }
    //printf("max long = %d\n",max_long);
    //print1();
    //print2();
    for(i=0; i<=max_long; i++)
    {
        //printf("%d ",i%10);
    }
    //printf("\n");
    bool check_find = false;
    find_right_from_down();
    for(j=my_ans.size()-1; j>=1; j--)
    {
        if(my_ans[j] == 0 && my_ans[j-1] == 0)
        {
            my_ans.erase(my_ans.begin()+j);
            //my_ans.erase(my_ans.begin()+j-1);
        }
    }
    if(my_ans[my_ans.size()-1] == 0)
    {
        my_ans.erase(my_ans.begin()+my_ans.size()-1);
    }
    for(i=0; i<my_ans.size(); i++)
    {
        printf("%d ",my_ans[i]);
    }
    printf("0");
    return 0;
}
void find_right_from_down()
{
    //getch();
    //printf("find right from down\n");
    for(this_x=this_x+1; this_x <= max_long; this_x++)
    {
        if(string1[this_y][this_x] == '*')
        {
            my_ans.push_back(this_x);
            //printf("x = %d\n",this_x);
            //printf("y = %d\n",this_y);
            break;
        }
    }
    find_up();
}
void find_up()
{
    //getch();
    //printf("find up\n");
    for(this_y=this_y; this_y < max_high; this_y++)
    {
        if(string1[this_y+1][this_x] == ' ' || this_y+1 == max_high)
        {
            my_ans.push_back(this_y+1);
            //printf("x = %d\n",this_x);
            //printf("y = %d\n",this_y);
            break;
        }
    }

    find_right();
}
void find_right()
{
    //getch();
    //printf("find_right\n");
    for(this_x = this_x; this_x <= max_long; this_x++)
    {
        if(string1[this_y][this_x] == '+')
        {
            //printf("can find +\n");
            my_ans.push_back(this_x);
            //printf("x = %d\n",this_x);
            //printf("y = %d\n",this_y);
            find_up();
            break;
        }
        if(string1[this_y][this_x] == ' ' || this_x == max_long)
        {
            //printf("can find space or max long\n");
            if(string1[this_y][this_x] == ' ')
            {
                this_x--;
            }
            my_ans.push_back(this_x);
            //printf("x = %d\n",this_x);
            //printf("y = %d\n",this_y);
            find_down();
            break;
        }
    }

}
void find_down()
{
    //getch();
    //printf("find down\n");
    for(this_y = this_y; this_y>=0; this_y--)
    {
        if(string1[this_y][this_x] == '+')
        {
            //printf("can find + in down\n");
            //printf("x = %d\n",this_x);
            //printf("y = %d\n",this_y);
            my_ans.push_back(this_y+1);
            this_x++;
            find_right();
        }
    }
    this_y++;
    my_ans.push_back(this_y);
    //printf("can't find + in down\n");
    //printf("x = %d\n",this_x);
    //printf("y = %d\n",this_y);
    if(this_y==0 && this_x == max_long)
    {
        //printf("end\n");
    }
    else
    {
        find_right_from_down();
    }

}
void print1()
{
    for(int i=0; i<max_high; i++)
    {
        for(int j=0; j<=max_long; j++)
        {
            printf("%c ",string1[i][j]);
        }
        printf("\n");
    }
}
void print2()
{
    for(int i=max_high-1; i>=0; i--)
    {
        for(int j=0; j<=max_long; j++)
        {
            printf("%c ",string1[i][j]);
        }
        printf("\n");
    }
}

