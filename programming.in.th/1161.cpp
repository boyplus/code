#include <cstdio>
#include <queue>
using namespace std;
queue <int> q_y,q_x,co,old_y,old_x;
char sewer[110][110];
int save[110][110];
int main()
{
    int i,j,k,m,n;
    scanf("%d %d",&m,&n);
    for(i=0; i<m; i++)
        for(j=0; j<n; j++)
            scanf(" %c",&sewer[i][j]);
    q_y.push(0);
    q_x.push(0);
    old_y.push(-1);
    old_x.push(-1);
    co.push(1);
    while(!q_y.empty())
    {
        if(save[q_y.front()][q_x.front()])
        {
            printf("%d\n%d %d",co.front(),q_y.front()+1,q_x.front()+1);
            return 0;
        }
        save[q_y.front()][q_x.front()] = co.front();
        if(sewer[q_y.front()][q_x.front()] == 'B')
        {
            if(q_x.front()+1 != old_x.front())
            {
                q_y.push(q_y.front());
                q_x.push(q_x.front()+1);
                co.push(co.front()+1);
                old_y.push(q_y.front());
                old_x.push(q_x.front());
            }
            if(q_y.front()+1 != old_y.front())
            {
                q_y.push(q_y.front()+1);
                q_x.push(q_x.front());
                co.push(co.front()+1);
                old_y.push(q_y.front());
                old_x.push(q_x.front());
            }
        }
        if(sewer[q_y.front()][q_x.front()] == 'R' && q_x.front()+1 != old_x.front())
        {
            q_y.push(q_y.front());
            q_x.push(q_x.front()+1);
            co.push(co.front()+1);
            old_y.push(q_y.front());
            old_x.push(q_x.front());
        }
        if(sewer[q_y.front()][q_x.front()] == 'D' && q_y.front()+1 != old_y.front())
        {
            q_y.push(q_y.front()+1);
            q_x.push(q_x.front());
            co.push(co.front()+1);
            old_y.push(q_y.front());
            old_x.push(q_x.front());
        }
        if(sewer[q_y.front()][q_x.front()-1] == 'R' || sewer[q_y.front()][q_x.front()-1] == 'B')
        {
            if(q_x.front()-1 != old_x.front())
            {
                q_y.push(q_y.front());
                q_x.push(q_x.front()-1);
                co.push(co.front()+1);
                old_y.push(q_y.front());
                old_x.push(q_x.front());
            }
        }
        if(sewer[q_y.front()-1][q_x.front()] == 'D' || sewer[q_y.front()-1][q_x.front()] == 'B')
        {
            if(q_y.front()-1 != old_y.front())
            {
                q_y.push(q_y.front()-1);
                q_x.push(q_x.front());
                co.push(co.front()+1);
                old_y.push(q_y.front());
                old_x.push(q_x.front());
            }
        }
        q_y.pop();
        q_x.pop();
        co.pop();
        old_y.pop();
        old_x.pop();
    }
    return 0;
}