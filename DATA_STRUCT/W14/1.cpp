#include <bits/stdc++.h>
#define int long long
using namespace std;

const int inf = INT64_MAX/3, MaxN = 1e3;

vector<vector<int>> gra(MaxN);
vector<int> vis(MaxN), path;

void dfs( int node ) {
    if( vis[node] ) return;
    vis[node] = 1;
    path.push_back(node);
    for( int i : gra[node] ) dfs(i);
}

void bfs() {
    queue<int> q;
    q.push(0);
    vis = vector<int>(MaxN, 0);
    vis[0] = 1;
    while( !q.empty() ) {
        int node = q.front(); q.pop();
        path.push_back(node);
        for( int i : gra[node] ) {
            if( vis[i] ) continue;
            vis[i] = 1;
            q.push(i);
        }
    }
}

void print() {
    for( int i=0 ; i < path.size() ; i++ ) cout << path[i] << " \n"[i+1 == path.size()];
}

signed main()
{
    ios_base::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int a, b;
    for(; cin >> a && a != -1 && cin >> b ;) {
        gra[a].push_back(b);
        gra[b].push_back(a);
    }
    path = vector<int>();
    dfs(0);
    cout << "Depth First Search:\n";
    print();
    path = vector<int>();
    cout << "\nBreadth First Search:\n";
    bfs();
    print();
}