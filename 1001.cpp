#include<iostream>
using namespace std;
int main()
{
    int m,n;
    cin >> m >> n;
    char str[m][n];
    for(int i=0;i<m;i++)
        cin >> str[i];
    int brick[n];
    for(int i=0;i<n;i++)
        cin >> brick[i];
    int max_brick=0;
    for(int i=0;i<n;i++)
        if(max_brick<brick[i])
            max_brick=brick[i];
    for(int i=0;i<max_brick;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(str[0][j]=='.'&&brick[j]>0)
            {
                brick[j]--;
                str[0][j]='#';
            }
        }
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<m-1;k++)
            {
                if(str[k][j]=='#'&&str[k+1][j]=='.')
                {
                    char x=str[k][j];
                    str[k][j]=str[k+1][j];
                    str[k+1][j]=x;
                }
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cout << str[i][j];
        cout << "\n";
    }
}
