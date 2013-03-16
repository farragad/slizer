//
//  EdmondsKarpMaxFlow.cpp
//  slizer
//	
#include <vector>
#include <iostream>
using namespace std;
const int inf = 1000*1000*1000;
typedef vector<int> graf_line;
typedef vector<graf_line> graf;

typedef vector<int> vint;
typedef vector<vint> vvint;


int main()
{
	int n;
	cin >> n;
	vvint c (n, vint(n));
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> c[i][j];

	vvint f (n, vint(n));
	for (;;) //spec your own limits
	{
		
		vint from (n, -1);
		vint q (n);
		int h=0, t=0;
		q[t++] = 0;
		from[0] = 0;
		for (int cur; h<t;)
		{
			cur = q[h++];
			for (int v=0; v<n; v++)
				if (from[v] == -1 &&
					c[cur][v]-f[cur][v] > 0)
				{
					q[t++] = v;
					from[v] = cur;
				}
		}

		if (from[n-1] == -1)
			break;
		int cf = inf;
		for (int cur=n-1; cur!=0; )
		{
			int prev = from[cur];
			cf = min (cf, c[prev][cur]-f[prev][cur]);
			cur = prev;
		}

		for (int cur=n-1; cur!=0; )
		{
			int prev = from[cur];
			f[prev][cur] += cf;
			f[cur][prev] -= cf;
			cur = prev;
		}

	}

	int flow = 0;
	for (int i=0; i<n; i++)
		if (c[0][i])
			flow += f[0][i];

	cout << flow;

}