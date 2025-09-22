#include <bits/stdc++.h>
#define int long long
using namespace std;

void print(vector<int>& arr) {
    cout<<"[";
    for( int i : arr ) cout<<i;
    cout<<"] ";
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n = 1;
    vector<int> arr;
    for(; cin >> t ;) {
        arr.push_back(t);
        if( arr.size() == n ) {
            n <<= 1;
            print(arr);
            arr = vector<int>();
        }
    }
    print(arr);
}