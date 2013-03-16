//
//  Dijkstra.cpp
//  cgraph
//
#include <vector>
#include <utility>
using namespace std;
const int INF = 1000000000 ;

void reverse(int t, int s, vector<int> p)
{
    vector < int > path ;
    for ( int v = t ; v != s ; v = p [ v ] )
        path. push_back ( v ) ;
    path. push_back ( s ) ;
    reverse ( path. begin ( ) , path. end ( ) ) ;
}

int main ( ) {
	int n ;
	//read in nodes
	vector < vector < pair < int , int > > > g ( n ) ;
	//make edges
	int s = n; //change s accordingly
    
	vector < int > d ( n, INF ) ,  p ( n ) ;
	d [ s ] = 0 ;
	vector < char > u ( n ) ;
	for ( int i = 0 ; i < n ; ++ i ) {
		int v = - 1 ;
		for ( int j = 0 ; j < n ; ++ j )
			if ( ! u [ j ] && ( v == - 1 || d [ j ] < d [ v ] ) )
				v = j ;
		if ( d [ v ] == INF )
			break ;
		u [ v ] = true ;
        
		for ( size_t j = 0 ; j < g [ v ] . size ( ) ; ++ j ) {
			int to = g [ v ] [ j ] . first ,
            len = g [ v ] [ j ] . second ;
			if ( d [ v ] + len < d [ to ] ) {
				d [ to ] = d [ v ] + len ;
				p [ to ] = v ;
			}
		}
	}
}