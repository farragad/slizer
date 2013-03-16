//
//  PrimSparseMST.cpp
//  cgraph
//
#include <vector>
#include <iostream>
#include <utility>
#include <set>
using namespace std;
int n ;
vector < vector < pair < int , int > > > g ;
const int INF = 1000000000 ; // значение "бесконечность"

void sparse_prim()
{
    vector < int > min_e ( n, INF ) , sel_e ( n, - 1 ) ;
    min_e [ 0 ] = 0 ;
    set < pair < int , int > > q ;
    q. insert ( make_pair ( 0 , 0 ) ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( q. empty ( ) ) {
            cout << "No MST!" ;
            exit ( 0 ) ;
        }
        int v = q. begin ( ) -> second ;
        q. erase ( q. begin ( ) ) ;
        
        if ( sel_e [ v ] != - 1 )
            cout << v << " " << sel_e [ v ] << endl ;
        
        for ( size_t j = 0 ; j < g [ v ] . size ( ) ; ++ j ) {
            int to = g [ v ] [ j ] . first ,
			cost = g [ v ] [ j ] . second ;
            if ( cost < min_e [ to ] ) {
                q. erase ( make_pair ( min_e [ to ] , to ) ) ;
                min_e [ to ] = cost ;
                sel_e [ to ] = v ;
                q. insert ( make_pair ( min_e [ to ] , to ) ) ;
            }
        }
    }
}