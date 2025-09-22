#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = INT64_MAX/3, MaxN = 1e3;

vector<vector<int>> graph(MaxN);

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int a, b, n = 0;
    for(; cin >> a && a != -1 && cin >> b ;) {
        graph[a].push_back(b);
        graph[b].push_back(a);
        n = max({n, a, b});
    }
    int adj[n+1][n+1];
    memset(adj, 0, sizeof(adj));
    for( int i=0 ; i <= n ; i++ ) {
        sort(graph[i].begin(), graph[i].end());
        graph[i].resize(unique(graph[i].begin(), graph[i].end()) - graph[i].begin());
        for( int j : graph[i] ) adj[i][j] = adj[j][i] = 1;
    }
    cout << "Adjacency matrix:\n";
    for( int i=0 ; i <= n ; i++ ) {
        for( int j=0 ; j <= n ; j++ ) cout << adj[i][j] << " ";
        cout << "\n";
    }
    cout << "\nAdjacency list:\n";
    for( int i=0 ; i <= n ; i++ ) {
        cout << i << ": ";
        for( int j : graph[i] ) cout << j << " -> ";
        cout << "end\n";
    }
}