#include <cstdio>
#include <vector>
using namespace std;
char str[3][20],temp[3][20];
char mp[10][3][3] = {'+','_','+','|','+','|','|','_','|'
                     ,'+','+','+','+','+','|','+','+','|'
                     ,'+','_','+','+','_','|','|','_','+'
                     ,'+','_','+','+','_','|','+','_','|'
                     ,'+','+','+','|','_','|','+','+','|'
                     ,'+','_','+','|','_','+','+','_','|'
                     ,'+','_','+','|','_','+','|','_','|'
                     ,'+','_','+','+','+','|','+','+','|'
                     ,'+','_','+','|','_','|','|','_','|'
                     ,'+','_','+','|','_','|','+','_','|'
                    };
vector<int> can1,can2,can3,can4;
int main()
{
    int i,j,sum_all = 0;;
    for(i=0; i<3; ++i)
        gets(temp[i]);
    for(i=0; i<3; ++i)
        for(j=0; j<13; ++j)
            str[i][j] = '+';
    for(i=0; i<3; ++i)
        for(j=0; j<13; ++j)
            if(temp[i][j] == '|' || temp[i][j] == '_' || temp[i][j] == '.')
                str[i][j] = temp[i][j];
    for(i=0; i<=2; ++i)
    {
        bool chk = true;
        for(int y=0; y<3; ++y)
        {
            for(int x=0; x<3; ++x)
            {
                if(str[y][x] != '+')
                {
                    if(str[y][x] != mp[i][y][x])
                    {
                        chk = false;
                        break;
                    }
                }
            }
            if(!chk)
                break;
        }
        if(chk)
            can1.push_back(i);
    }
    for(i=0; i<=9; ++i)
    {
        bool chk = true;
        for(int y=0; y<3; ++y)
        {
            for(int x=0; x<3; ++x)
            {
                if(str[y][x+3] != '+')
                {
                    if(str[y][x+3] != mp[i][y][x])
                    {
                        chk = false;
                        break;
                    }
                }
            }
            if(!chk)
                break;
        }
        if(chk)
            can2.push_back(i);
    }
    for(i=0; i<=5; ++i)
    {
        bool chk = true;
        for(int y=0; y<3; ++y)
        {
            for(int x=0; x<3; ++x)
            {
                if(str[y][x+7] != '+')
                {
                    if(str[y][x+7] != mp[i][y][x])
                    {
                        chk = false;
                        break;
                    }
                }
            }
            if(!chk)
                break;
        }
        if(chk)
            can3.push_back(i);
    }
    for(i=0; i<=9; ++i)
    {
        bool chk = true;
        for(int y=0; y<3; ++y)
        {
            for(int x=0; x<3; ++x)
            {
                if(str[y][x+10] != '+')
                {
                    if(str[y][x+10] != mp[i][y][x])
                    {
                        chk = false;
                        break;
                    }
                }
            }
            if(!chk)
                break;
        }
        if(chk)
            can4.push_back(i);
    }
    int size_1 = can1.size(),size_2 = can2.size(),size_3 = can3.size(),size_4 = can4.size();
    for(int a=0; a<size_1; ++a)
    {
        for(int b=0; b<size_2; ++b)
        {
            for(int c=0; c<size_3; ++c)
            {
                for(int d=0; d<size_4; ++d)
                {
                    ++sum_all;
                    if(can1[a] == 2)
                        if(can2[b] > 3)
                            --sum_all;
                }
            }
        }
    }
    printf("%d\n",sum_all);
    return 0;
}
