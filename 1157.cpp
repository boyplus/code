#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
class Node
{
public:
    int id;
    int cost;
    Node(int id,int cost)
    {
        this->id = id;
        this->cost = cost;
    }
};
struct compare
{
    bool operator()(const Node& e0,const Node& e1)
    {
        return e0.cost > e1.cost;
    };
};
int main()
{
    priority_queue<Node,vector<Node>,compare> pq;
    int i,k,n;
    scanf("%d %d",&n,&k);
    vector<int> prices(n);
    for(i=0;i<n;++i)
        scanf("%d",&prices[i]);
    pq.push(Node(0,prices[0]));
    int total_price = 0;
    for(i=1;i<n;++i)
    {
        while(pq.top().id + k < i)
            pq.pop();
        Node node = pq.top();
        total_price = node.cost + prices[i];
        pq.push(Node(i,total_price));
    }
    printf("%d\n",total_price);
    return 0;
}
