#include <bits/stdc++.h>
#define int long long
#define cl(x) (x*2)
#define cr(x) (x*2+1)
using namespace std;
 
const int INF = INT64_MAX/3, modl=1e9+7, MAXN = 2e5;
vector<int> arr(2e3, -1);

int h( int node ) {
    if( arr[node] == -1 ) return 0;
    return max( h(cl(node)), h(cr(node)) ) + 1;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    queue<int> q;
    q.push(1);
    for(; cin >> t ;) {
        int node = q.front(); q.pop();
        if(t == -1) continue;
        arr[node] = t;
        q.push(cl(node)); q.push(cr(node));
    }
    cout << h(1) << '\n';
}