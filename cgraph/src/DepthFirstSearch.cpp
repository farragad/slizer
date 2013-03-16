//
//  DepthFirstSearch.cpp
//  cgraph
//
#include <vector>
using namespace std;

void dfs (int v) {
    vector < vector<int> > g;
    vector<int> color;
    vector<int> time_in, time_out;
    
    int n;
    int dfs_timer = 0;
	
    time_in[v] = dfs_timer++;
	color[v] = 1;
	for (vector<int>::iterator i=g[v].begin(); i!=g[v].end(); ++i)
		if (color[*i] == 0)
			dfs (*i);
	color[v] = 2;
	time_out[v] = dfs_timer++;
}

void vanilla(int v)
{
    vector<vector<int> > g;
    int n;
    
    vector <char> used;
    used [v] = true;
    for (vector <int> :: iterator i = g [v]. begin (); i != g [v]. end (); ++i)
        if (! used [* i])
            dfs (* i);

}