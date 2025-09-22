#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    int n;
    vector<int> fa, sz;
    DSU( int _n ): n(_n) {
        fa = sz = vector<int>(n + 1, 1);
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int find( int x ) {
        if( x == fa[x] ) return x;
        return fa[x] = find(fa[x]);
    }
    bool merge( int x, int y ) {
        x = find(x), y = find(y);
        if( x == y ) return 1;
        if( sz[x] < sz[y] ) swap(x, y);
        fa[y] = x;
        sz[x] += sz[y];
        return 0;
    }
};

void MST( vector<Edge> &edges, int n ) {
    sort(edges.begin(), edges.end(), [&]( Edge a, Edge b ) {
        return a.w < b.w;
    });
    vector<Edge> mst;
    DSU dsu(n);
    int ans = 0;
    for (auto e : edges) {
        if (dsu.merge(e.u, e.v)) continue;
        ans += e.w;
        mst.push_back(e);
    }
    int cnt = 1;
    for (auto e : mst) cout << cnt++ << ": <" << e.u << "," << e.v << ">\n";
    cout << "The cost of minimum spanning tree: " << ans << "\n";
}

int main()
{
    int n = 0;
    vector<Edge> edges;
    int a, b, c;
    while (cin >> a && a != -1 && cin >> b >> c ) edges.push_back({a, b, c}), n = max(n, max(a, b));
    MST(edges, n+1);
}