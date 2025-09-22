#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
const int INF = INT64_MAX/3, modl=1e9+7, MAXN = 2e5;

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, b, i = 1;
    cin>>n>>a>>b;
    vector<int> arr(n);
    for( int i=0 ; i < n ; i++ ) arr[i] = i;
    i = a-1;
    for( ; arr.size() ; ) {
        for( int j=0 ; j < b-1 ; i= (i+1)%arr.size(), j++ ) ;
        // cout<<i<<" ";
        cout<<arr[i]+1<<" ";
        arr.erase(arr.begin()+i);
        
    }
}