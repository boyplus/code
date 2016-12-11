#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
void clear_vec(int);
vector<int> tree1_normal[100002],tree2_normal[100002];
int main()
{
    for(int x=0; x<5; ++x)
    {
        int i,j,k,n,node1,node2,max1=-1,max2=-1,temp=0;
        scanf("%d",&n);
        for(i=1; i<n; ++i)
        {
            scanf("%d %d",&node1,&node2);
            if(node1 > node2)
            {
                temp = node1;
                node1 = node2;
                node2 = temp;
            }
            if(node1 > max1)
                max1 = node1;
            if(node2 > max1)
                max1 = node2;
            tree1_normal[node1].push_back(node2);
        }
        for(i=1; i<n; ++i)
        {
            scanf("%d %d",&node1,&node2);
            if(node1 > node2)
            {
                temp = node1;
                node1 = node2;
                node2 = temp;
            }
            if(node1 > max2)
                max2 = node1;
            if(node2 > max2)
                max2 = node2;
            tree2_normal[node1].push_back(node2);
        }
        if(max1!=max2)
        {
            printf("N");
            if(max1 > max2)
            {
                for(int z=0; z<=max1; ++z)
                {
                    tree1_normal[z].clear();
                    tree2_normal[z].clear();
                }
            }
            else
            {
                for(int z=0; z<=max2; ++z)
                {
                    tree1_normal[z].clear();
                    tree2_normal[z].clear();
                }
            }
            break;
        }
        bool chk = false;
        for(i=0; i<=max1; ++i)
        {
            int size1 = tree1_normal[i].size();
            int size2 = tree2_normal[i].size();
            sort(tree1_normal[i].begin(),tree1_normal[i].end());
            sort(tree2_normal[i].begin(),tree2_normal[i].end());
            if(size1!=size2)
            {
                printf("N");
                chk = true;
                break;
            }
            for(j=0; j<size1; ++j)
            {
                if(tree1_normal[i].at(j) != tree2_normal[i].at(j))
                {
                    chk = true;
                    break;
                }
            }
            if(chk)
            {
                printf("N");
                break;
            }
        }
        if(!chk)
            printf("Y");
        for(int z=0; z<=max1; ++z)
        {
            tree1_normal[z].clear();
            tree2_normal[z].clear();
        }
    }

    return 0;
}
