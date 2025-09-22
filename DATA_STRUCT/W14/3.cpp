#include <bits/stdc++.h>
using namespace std;
const int inf = INT64_MAX/3;

unordered_map<char,int> vis, dis;
unordered_map<char,char> fa;
unordered_map<char,vector<pair<int,char>>> graph;

void dijkstra( char a, char b ) {
    for(auto &i: graph) {
        vis[i.first] = 0;
        dis[i.first] = inf;
        fa[i.first] = 0;
    }
    dis[a] = 0;
    priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> pq;
    pq.push({0, a});
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if( vis[u] ) continue;
        vis[u] = 1;
        for(auto &i: graph[u]) {
            auto [w, v] = i;
            if( dis[v] > dis[u] + w ) {
                dis[v] = dis[u] + w;
                fa[v] = u;
                pq.push({dis[v], v});
            }
        }
    }
    vector<char> path;
    for(char i=b; i!=a; i=fa[i]) path.push_back(i);
    path.push_back(a);
    reverse(path.begin(), path.end());
    for(int i=0 ; i < path.size() ; i++) {
        cout << path[i];
        if(i+1 != path.size()) cout << "->";
    }
    cout << " (Shortest Path:" << dis[b] << ")\n";
    return;
}

int main()
{
    string str;
    for(;getline(cin, str);) {
        stringstream ss(str);
        string a, b, c;
        ss >> a >> b;
        if(a != "Dijkstra") {
            int x;
            ss >> x;
            graph[a[0]].push_back({x, b[0]});
            graph[b[0]].push_back({x, a[0]});
        }
        else {
            ss >> c;
            dijkstra(b[0], c[0]);
        }
    }
}