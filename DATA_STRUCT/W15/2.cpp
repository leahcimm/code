#include <bits/stdc++.h>
#define int long long
using namespace std;

void PrimMST(vector<vector<pair<int,int>>> &graph, int n, int st ) {
    vector<int> key(n, INT64_MAX/3);
    vector<bool> mst(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, st});
    key[st] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        mst[u] = 1;
        for (auto it : graph[u]) {
            int v = it.second;
            int weight = it.first;
            if ( !mst[v] && weight < key[v] ) {
                key[v] = weight;
                pq.push({key[v], v});
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) ans += key[i];
    cout << ans << "\n";
        
}

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<vector<pair<int, int>>> graph(1000);
    int a, b, c, st, n = 0;
    cin >> st;
    while (cin >> a && a != -1 && cin >> b >> c ) graph[a].push_back({c, b}), graph[b].push_back({c, a}), n = max(n, max(a, b));
    PrimMST(graph, n+1, st);
}