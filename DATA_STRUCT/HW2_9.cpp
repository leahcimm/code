#include <bits/stdc++.h>
using namespace std;

struct edge {
    int u, v, w;
};

signed main()
{
    const int INF = 1e18, MAXN = 1e2;
    int a, b, c, n = 0;
    vector<edge> edges;
    vector<int> dis(MAXN, INF);
    for(; cin>> a >> b >> c;) edges.push_back({a, b, c}), n = max({n, a, b});
    dis[0] = 0;
    for (int i = 0; i < n; ++i){
        for (auto e :edges){
            dis[e.v] = min(dis [e.v], dis[e.u] + e.w);
        }
    }
    
    for(int i=0; i<=n; i++){
        cout << "dis[" << i << "] ="<< dis[i] << '\n';
    }
}
    