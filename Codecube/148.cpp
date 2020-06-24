#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <math.h>
using namespace std;
const int N = 50010;
const int LG = 20;
vector< vector< int > > query;
map< int, int > pos;
set< int > coor;
vector< int > front, back;
vector< int > flip;
int n, m;
// max RMQ
vector< vector< int > > RMQ;
void initRMQ( void );
int rmq( int, int ); // get max between two indices
// Fenwick Tree
vector< int > Fenwick;
void updateFenwick( int, int ); // update fenwick tree
int queryFenwick( int ); // query fenwick tree
int main( void ) {
    // read input
    cin >> n >> m;
    front.resize(n);
    back.resize(n);
    flip.resize(m);
    for ( int i = 0 ; i < n ; ++i ) {
        cin >> front[i] >> back[i];
    }
    for ( int i = 0 ; i < m ; ++i ) {
        cin >> flip[i];
    }
    // compress the coordinate
    for ( int i = 0 ; i < n ; ++i ) {
        coor.insert( front[i] );
        coor.insert( back[i] );
    }
    for (int i=0;i<flip.size();i++) {
        coor.insert( flip[i] );
    }
    int cnt = 0;
    for ( int x : coor ) {
        pos[ x ] = cnt++;
    }
    // process max RMQ
    initRMQ();
    query.resize( m );
    for ( int i = 0 ; i < n ; ++i ) {
        auto card = minmax( { front[i], back[i] } );
        int idx = rmq( pos[ card.first ], pos[ card.second ] - 1 );
        if ( idx != -1 ) {
            front[i] = card.second;
            back[i] = card.first;
        }
        query[ max( idx, 0 ) ].push_back( i );
    }
    Fenwick.resize( coor.size() + 1, 0 );
    for ( int i = m-1 ; i >= 0 ; --i ) {
        updateFenwick( Fenwick.size() - pos[ flip[i] ], 1 );
        for ( int id : query[i] ) {
            auto card = minmax( { front[id], back[id] } );
            int tflip = queryFenwick( Fenwick.size() - pos[ card.second ] );
            if ( tflip % 2 == 1 ) {
                swap( front[id], back[id] );
            }
        }
    }
    // report answer
    for ( int i = 0 ; i < n ; ++i ) {
        cout << front[i] << "\n";
    }
    return 0;
}
void initRMQ( void ) {
    RMQ.resize( coor.size(), vector< int > ( LG, -1 ) );
    for ( int i = 0 ; i < m ; ++i ) {
        RMQ[ pos[ flip[i] ] ][ 0 ] = i;
    }
    for ( int j = 1 ; j < LG ; ++j ) {
        for ( int i = 0 ; i < coor.size() ; ++i ) {
            int nwi = i + ( 1 << (j-1) );
            RMQ[i][j] = max( RMQ[i][j-1], ( nwi < RMQ.size() ? RMQ[ nwi ][ j-1
                                                                          
                                                                          ] : -1 ) );
        }
    }
}
int rmq( int l, int r ) {
    if ( l > r ) return -1;
    int lg = log2( r - l + 1 );
    return max( RMQ[ l ][ lg ], RMQ[ r - ( 1 << lg ) + 1 ][ lg ] );
}
void updateFenwick( int idx, int val ) {
    while ( idx < Fenwick.size() ) {
        Fenwick[ idx ] += val;
        idx += idx & ( -idx );
    }
}
int queryFenwick( int idx ) {
    int ans = 0;
    while ( idx > 0 ) {
        ans += Fenwick[ idx ];
        idx -= idx & ( -idx );
    }
    return ans;
}