#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<char> way;
int main()
{
    int i,j,k,m,n,cost[270],count_find=0,count_data=0;
    char fact1[270],fact2[270],data1[26] = "",data2[26] = "",start = ' ',end = ' ',temp = ' ';
    float sum=0.00;
    for(i=0; i<26; i++)
    {
        data1[i] = '-';
        data2[i] = '-';
    }
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf(" %c %c %d",&fact1[i],&fact2[i],&cost[i]);
        if(fact1[i]!= 'X' && fact1[i] != 'Y' && fact2[i]!= 'X' && fact2[i] != 'Y')
        {
            data1[fact1[i]-97] = fact2[i];
            data2[fact2[i]-97] = fact1[i];
            count_data++;
        }
        if(fact1[i] == 'X')
            start = fact2[i];
        if(fact2[i] == 'X')
            start = fact1[i];
        if(fact1[i] == 'Y')
            end = fact2[i];
        if(fact2[i] == 'Y')
            end = fact1[i];
        if(fact1[i] != 'X' && fact1[i]!= 'Y')
            temp = fact1[i];
        if(fact2[i] != 'X' && fact2[i] != 'Y')
            temp = fact2[i];
    }
    if(count_data == 0)
    {
        way.push_back('X');
        way.push_back(temp);
        way.push_back('Y');
        vector<int> cost_all;
        for(i=0; i<2; i++)
        {
            char link_1 = way[i],link_2 = way[i+1];
            printf("%c %c ",link_1,link_2);
            for(j=0; j<n; j++)
                if((fact1[j] == link_1 &&  fact2[j] == link_2) || (fact2[j] == link_1 && fact1[j] == link_2))
                    cost_all.push_back(cost[j]);
            int cost_size = cost_all.size();
            sort(cost_all.begin(),cost_all.end());
            float median = 0.00;
            if(cost_size%2)
                median = cost_all[(cost_size+1)/2-1];
            else
                median = (cost_all[cost_size/2-1] + cost_all[cost_size/2]) / 2.00;
            sum+=median;
            printf("%.1f\n",median);
        }
        printf("%.1f\n",sum);
        return 0;
    }
    way.push_back('X');
    bool can_find = false;
    char now_node = start,prev_node = 'X';
    while(!can_find)
    {
        way.push_back(now_node);
        bool chk_find = false;
        if(data1[now_node-97] != '-' && prev_node != data1[now_node-97])
        {
            prev_node = now_node;
            now_node = data1[now_node-97];
            chk_find = true;
        }
        else if(data2[now_node-97] != '-' && prev_node != data2[now_node-97])
        {
            prev_node = now_node;
            now_node = data2[now_node-97];
            chk_find = true;
        }
        if(chk_find == false)
        {
            for(j=0; j<26; j++) //data 1
            {
                if(data1[j] == now_node && j+97 != prev_node)
                {
                    prev_node = now_node;
                    now_node = j+97;
                    chk_find = true;
                    break;
                }
                if(data2[j] == now_node && j+97 != prev_node)
                {
                    prev_node = now_node;
                    now_node = j+97;
                    chk_find = true;
                    break;
                }
            }
        }
        if(now_node == end)
        {
            way.push_back(now_node);
            can_find = true;
        }
        count_find++;
        if(count_find > 270)
        {
            printf("broken\n");
            return 0;
        }
    }
    way.push_back('Y');
    int way_size = way.size()-1;
    for(i=0; i<way_size; i++)
    {
        char link_1 = way[i],link_2 = way[i+1];
        printf("%c %c ",link_1,link_2);
        vector<int> cost_all;
        for(j=0; j<n; j++)
            if((fact1[j] == link_1 && fact2[j] == link_2) || (fact2[j] == link_1 && fact1[j] == link_2))
                cost_all.push_back(cost[j]);
        int cost_size = cost_all.size();
        sort(cost_all.begin(),cost_all.end());
        float median = 0.00;
        if(cost_size%2)
            median = cost_all[(cost_size+1)/2-1];
        else
            median = (cost_all[cost_size/2-1] + cost_all[cost_size/2]) / 2.00;
        sum+=median;
        printf("%.1f\n",median);
    }
    printf("%.1f\n",sum);
    return 0;
}
