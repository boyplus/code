#include <stdio.h>
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
    table[3][3]=2;
    table[4][4]=2;
    print();
    for(i=0; i<n; i++)
    {
        //printf("this turn = %d\n",turn);
        int row;
        char column;
        scanf(" %c %d",&column,&row);
        column = (column-'a');
        table[row-1][column] = turn;
        turn = 1-turn;
        print();
    }
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
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
void left(int turn,int i,int j)
{
    int oppo=1;
    if(turn==1)
        oppo=2;
    while(table[i][j]);
}
void right(int turn,int i,int j)
{

}
void up(int turn,int i,int j)
{

}
void down(int turn,int i,int j)
{

}
void up_left(int turn,int i,int j)
{


}
void up_right(int turn,int i,int j)
{

}
void down_left(int turn,int i,int j)
{

}
void down_right(int turn,int i,int j)
{

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

