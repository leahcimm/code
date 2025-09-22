#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    vector<vector<pair<int,int>>> graph; 
    int ui, vi, wi;
    vector<array<int,3>> edges(t);
    for (int i = 0; i < t; i++) {
        cin >> ui >> vi >> wi;
        edges[i] = {ui, vi, wi};
    }
    int n, k;
    cin >> n >> k;

    graph.assign(n+1, {});
    for (auto &e: edges) {
        graph[e[0]].push_back({e[1], e[2]});
    }

    const int INF = 1e9;
    vector<int> dist(n+1, INF);
    dist[k] = 0;

    // Dijkstra
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, k});

    while(!pq.empty()) {
        auto [cd, u] = pq.top();
        pq.pop();
        if (cd > dist[u]) continue;
        for (auto &edge: graph[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) {
            cout << -1 << "\n";
            return 0;
        }
        ans = max(ans, dist[i]);
    }

    cout << ans << "\n";

    return 0;
}
