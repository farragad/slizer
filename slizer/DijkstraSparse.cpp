//
//  DijkstraSparse.cpp
//  slizer
//
#include <vector>
#include <set>
#include <queue>
#include <utility>
using namespace std;
const int INF = 1000000000;

void with_priority_queue()
{
    int n;
	//read nodes
	vector < vector < pair<int,int> > > g (n);
	//read edges
	int s = n; //change yourself
    
	vector<int> d (n, INF),  p (n);
	d[s] = 0;
	priority_queue < pair<int,int> > q;
	q.push (make_pair (0, s));
	while (!q.empty()) {
		int v = q.top().second,  cur_d = -q.top().first;
		q.pop();
		if (cur_d > d[v])  continue;
        
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
            len = g[v][j].second;
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				p[to] = v;
				q.push (make_pair (-d[to], to));
			}
		}
	}
}

int main() {
	int n;
	//read in nodes
	vector < vector < pair<int,int> > > g (n);
	//read in edges
	int s = n; // change yourself
    
	vector<int> d (n, INF),  p (n);
	d[s] = 0;
	set < pair<int,int> > q;
	q.insert (make_pair (d[s], s));
	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase (q.begin());
        
		for (size_t j=0; j<g[v].size(); ++j) {
			int to = g[v][j].first,
            len = g[v][j].second;
			if (d[v] + len < d[to]) {
				q.erase (make_pair (d[to], to));
				d[to] = d[v] + len;
				p[to] = v;
				q.insert (make_pair (d[to], to));
			}
		}
	}
}