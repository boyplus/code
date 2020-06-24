#include <iostream>
#include <vector>
using namespace std;
const int N = 210;
typedef pair< int, int > pii;
vector< int > order;
vector< pii > ans;
vector< int > adj[ N ];
int n, m;
// dfs find all leaves
void dfs( int u, int p ) {
    // if the node is a leaf
    if ( adj[u].size() == 1 ) {
        order.push_back( u );
    }
    /*for ( int v : adj[u] ) {
        if ( v != p ) {
            dfs( v, u );
        }
    }*/
}
int main() {
    // read input
    cin >> n >> m;
    for ( int i = 0 ; i + 1 < n ; ++i ) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back( v );
        adj[v].push_back( u );
    }
    if ( n == 2 ) {
        // check for special case; no root according to the definition
        ans = { { 1, 2 } };
    } else {
        // find root
        int r = 1;
        while ( adj[r].size() == 1 ) {
            ++r;
        }
        // start DFS
        dfs( r, r );
        int len = ( (int)order.size() + 1 ) / 2;
        // connect the ith leaf with (i+len/2)th leaf
        for ( int i = 0 ; i < len ; ++i ) {
            ans.push_back( { order[i], order[ order.size() - len + i ] } );
        }
    }
    // report answer
    cout << ans.size() << "\n";
    if ( m == 2 ) {
        for ( pii e : ans ) {
            cout << e.first << " " << e.second << "\n";
        }
    }
    return 0;
}