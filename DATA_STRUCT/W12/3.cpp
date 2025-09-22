#include <bits/stdc++.h>
#define int long long
#define cl(x) (x*2)
#define cr(x) (x*2+1)
using namespace std;
 
const int INF = INT64_MAX/3, modl=1e9+7, MAXN = 2e5;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t;
    cin >> n;
    map<int,int> mp;
    for(; cin >> t && t != -1 ;) {
        if( !t ) continue;
        if( !mp[t] ) cout << t << ' ', mp[t] = 1;
    }
}