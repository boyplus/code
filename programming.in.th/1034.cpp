#include <stdio.h>
bool check_turn(int);
void check(int);
void print();
void left(int,int,int);
void right(int,int,int);
void up(int,int,int);
void down(int,int,int);
void up_left(int,int,int);
void up_right(int,int,int);
void down_left(int,int,int);
void down_right(int,int,int);
int table[10][10]= {0};
int main()
{
    //1 = black
    //2 = white
    int i,j,k,m,n,turn = 1;
    scanf("%d",&n);
    table[3][4]=1;
    table[4][3]=1;
    //table[3][6]=1;
    table[3][3]=2;
    //table[3][7]=2;
    table[4][4]=2;
    //print();
    for(i=0; i<n; i++)
    {
        //printf("this turn = %d\n",turn);
        int row;
        char column;
        scanf(" %c %d",&column,&row);
        bool chk = check_turn(turn);
        if(chk==true)
        {
            //row--;
            //printf("turn %d is walk\n",turn);
            column = (column-'a');
            //printf("co = %d\n",column);
            table[row-1][column] = turn;
            //turn++;
        }
        else
        {
            //printf("turn %d is can't walk\n",turn);
            //turn++;
            turn++;
            if(turn>2)
                turn = 1;
            continue;
        }
        check(1);
        check(2);
        turn++;
        if(turn >2)
            turn = 1;
        //print();
    }
    check(1);
    check(2);
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
        {
            if(table[i][j]==0)
                printf(".");
            else if(table[i][j]==1)
                printf("X");
            else if(table[i][j]==2)
                printf("O");
        }
        printf("\n");
    }
    return 0;
}
void check(int turn)
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            int count=0;
            if(table[i][j]==turn)
            {
                left(turn,i,j);
                right(turn,i,j);
                up(turn,i,j);
                down(turn,i,j);
                up_left(turn,i,j);
                up_right(turn,i,j);
                down_left(turn,i,j);
                down_right(turn,i,j);
            }
        }
    }
}
void left(int turn,int i,int j)
{
    bool chk = false;
    int oppo,start=j;
    if(turn ==1)
        oppo=2;
    else
        oppo=1;
    j--;
    while(table[i][j]==oppo&&j>0)
    {
        chk = true;
        j--;
    }
    if(table[i][j]==turn&&chk==true)
    {
        //printf("can delete %d to %d!!\n",start,j);
        for(int z=start-1; z>j; z--)
            table[i][z] = turn;
    }
}
void right(int turn,int i,int j)
{
    bool chk = false;
    int oppo,start=j;
    if(turn ==1)
        oppo = 2;
    else
        oppo=1;
    j++;
    while(table[i][j]==oppo&&j<7)
    {
        chk = true;
        j++;
    }
    if(table[i][j]==turn&&chk == true)
    {
        //printf("can delete %d to %d!!\n",start,j);
        for(int z = start+1; z<j; z++)
            table[i][z] = turn;
    }
}
void up(int turn,int i,int j)
{
    //printf("in up\n");
    bool chk = false;
    int start=i,oppo;
    if(turn==1)
        oppo = 2;
    else
        oppo = 1;
    i--;
    while(table[i][j]==oppo&&i>0)
    {
        chk = true;
        i--;
    }
    if(table[i][j]==turn&&chk == true)
    {
        //printf("can delete %d to %d!!\n",start,i);
        for(int z = start-1; z>i; z--)
            table[z][j] = turn;
    }
}
void down(int turn,int i,int j)
{
    //printf("in down\n");
    bool chk = false;
    int start=i,oppo;
    i++;
    if(turn==1)
        oppo = 2;
    else
        oppo = 1;
    while(table[i][j]==oppo && i<7)
    {
        chk = true;
        i++;
    }
    if(table[i][j]==turn&&chk==true)
    {
        //printf("can delete %d to %d!!\n",start,i);
        for(int z = start+z; z<i; z++)
            table[z][j] = turn;
    }
}
void up_left(int turn,int i,int j)
{
    //printf("in up_left\n");
    bool chk = false;
    int start_1=i,start_2=j,oppo;
    i--;
    j--;
    if(turn==1)
        oppo = 2;
    else
        oppo = 1;
    while(table[i][j]==oppo&&i>0&&j>0)
    {
        i--;
        j--;
        chk = true;
    }
    if(table[i][j]==turn&&chk==true)
    {
        //printf("can delete\n");
        int z = start_1-1;
        int x = start_2-1;
        for(; z>i&&x>j; z--,x--)
        {
            table[z][x] = turn;
        }
    }

}
void up_right(int turn,int i,int j)
{
    //printf("in up_right\n");
    bool chk = false;
    int start_1=i,start_2=j,oppo;
    i--;
    j++;
    if(turn==1)
        oppo = 2;
    else
        oppo = 1;
    while(table[i][j]==oppo&&i>0&&j<7)
    {
        i--;
        j++;
        chk = true;
    }
    if(table[i][j]==turn&&chk==true)
    {
        //printf("can delete\n");
        int z = start_1-1;
        int x = start_2+1;
        for(; z>i&&x<j; z--,x++)
        {
            table[z][x] = turn;
        }
    }
}
void down_left(int turn,int i,int j)
{
    bool chk = false;
    int start_1=i,start_2=j,oppo;
    i++;
    j--;
    if(turn==1)
        oppo = 2;
    else
        oppo = 1;
    while(table[i][j]==oppo&&i<7&&j>0)
    {
        i++;
        j--;
        chk = true;
    }
    if(table[i][j]==turn&&chk==true)
    {
        int z = start_1+1;
        int x = start_2-1;
        for(;z<i&&x>j;z++,x--)
        {
            table[z][x] = turn;
        }
    }
}
void down_right(int turn,int i,int j)
{
    bool chk = false;
    int start_1=i,start_2=j,oppo;
    i++;
    j++;
    if(turn==1)
        oppo = 2;
    else
        oppo = 1;
    while(table[i][j]==oppo&&i<7&&j<7)
    {
        i++;
        j++;
        chk = true;
    }
    if(table[i][j]==turn&&chk==true)
    {
        int z = start_1+1;
        int x = start_2+1;
        for(;z<i&&x<j;z++,x++)
        {
            table[z][x] = turn;
        }
    }
}
bool check_turn(int turn)
{
    bool have = false;
    int oppo;
    if(turn ==1)
        oppo = 2;
    else
        oppo = 1;
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if(table[i][j] == turn)
            {
                //left
                int y = i;
                int x = j-1;
                bool chk=false;
                while(x>0&&table[y][x]==oppo)
                {
                    x--;
                    chk=true;
                }
                if(chk==true&&table[y][x]==0)
                {
                    have = true;
                    //printf("can left\n");
                    return true;
                }

                //right
                y=i;
                x=j+1;
                chk=false;
                while(x<7&&table[y][x]==oppo)
                {
                    x++;
                    chk = true;
                }
                if(chk==true&&table[y][x]==0)
                {
                    have = true;
                    //printf("can right\n");
                    return true;
                }

                //up
                y = i-1;
                x = j;
                chk = false;
                while(y>0&&table[y][x]==oppo)
                {
                    y--;
                    chk = true;
                }
                if(chk==true&&table[y][x]==0)
                {
                    have = true;
                    //printf("can up\n");
                    return true;
                }

                //down
                y = i+1;
                x = j;
                chk = false;
                while(y<7&&table[y][x]==oppo)
                {
                    y++;
                    chk = true;
                }
                if(chk==true&&table[y][x] == 0)
                {
                    have = true;
                    //printf("can down\n");
                    return true;
                }

                //up left
                y = i-1;
                x = j-1;
                chk = false;
                while(y>0&&x>0&&table[y][x]==oppo)
                {
                    x--;
                    y--;
                    chk = true;
                }
                if(chk==true&&table[y][x]==0)
                {
                    have = true;
                    //printf("can up left\n");
                    return true;
                }

                //up right
                y = i-1;
                x = j+1;
                chk = false;
                while(y>0&&x<7&&table[y][x]==oppo)
                {
                    y--;
                    x++;
                    chk = true;
                }
                if(chk==true&&table[y][x]==0)
                {
                    have = true;
                    //printf("can up right\n");
                    return true;
                }

                //down left
                y = i+1;
                x = j-1;
                chk = false;
                while(y<7&&x>0&&table[y][x]==oppo)
                {
                    y++;
                    x--;
                    chk = true;
                }
                if(chk==true&&table[y][x]==0)
                {
                    have = true;
                    //printf("can down left\n");
                    return true;
                }

                //down right
                y = i+1;
                x = j+1;
                chk = false;
                while(y<7&&x<7&&table[y][x]==oppo)
                {
                    y++;
                    x++;
                    chk = true;
                }
                if(chk==true&&table[y][x]==0)
                {
                    have = true;
                    //printf("can down right\n");
                    return true;
                }
            }
        }
    }
    if(have == false)
    {
       return false;
    }

}
void print()
{
    printf("  ");
    for(int i='a'; i<='h'; i++)
        printf("%c ",i);
    printf("\n");
    for(int i=0; i<8; i++)
    {
        printf("%d ",i+1);
        for(int j=0; j<8; j++)
        {
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }
}
