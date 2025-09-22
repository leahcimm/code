#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b;
    string s;
    cin >> n;
    cin >> s;
    for( char &c : s ) if( c == '[' || c == ']' || c == ',' ) c = ' ';
    stringstream ss(s);
    vector<vector<int>> graph(n);
    vector<int> in(n);
    while( ss >> a >> b ) {
        graph[a].push_back(b);
        in[b]++;
    }
    queue<int> que;
    for (int i = 0; i < n; i++) if( !in[i] ) que.push(i);
    vector<int> ans;
    while( !que.empty() ) {
        int u = que.front(); que.pop();
        ans.push_back(u);
        for (int v : graph[u]) {
            in[v]--;
            if( !in[v] ) que.push(v);
        }
    }
    if( ans.size() != n ) cout << "false\n";
    else  cout << "true\n";
}