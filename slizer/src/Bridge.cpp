//
//  Bridge.cpp
//  slizer
//
#include <vector>
#define MAXN 1000000
using namespace std;
vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN];

void store_bridge(int v, int to)
{
    //whatever you want...
}

void dfs (int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (size_t i=0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (to == p)  continue;
		if (used[to])
			fup[v] = min (fup[v], tin[to]);
		else {
			dfs (to, v);
			fup[v] = min (fup[v], fup[to]);
			if (fup[to] > tin[v])
				store_bridge(v,to);
		}
	}
}

void find_bridges(int n) {
	timer = 0;
	for (int i=0; i<n; ++i)
		used[i] = false;
	for (int i=0; i<n; ++i)
		if (!used[i])
			dfs(i);
}