#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    string s;
    int t, r = 0, cnt = 0;
    vector<int> arr;
    for(;;) {
        cin>>s;
        if( s == "插入" ) {
            cin>>t;
            arr.push_back(t);
            cout<<"null\n";
        }
        if( s == "刪除" ) {
            cin>>t;
            if( t < arr.size() ) {
                arr.erase(arr.begin()+t);
                cout<<"true\n";
            }
            else cout<<"false\n";
        }
        if( s == "反轉" ) {
            reverse(arr.begin(), arr.end());
            cout<<"null\n";
        }
        if( s == "查找" ) {
            if( cnt == 0 ) r = arr.size()-1;
            cin>>t;
            if( arr[r] == t ) cout<<"true\n";
            else cout<<"false\n";
            r--;
            if( r < 0 ) r = arr.size()-1;
            cnt++;
        }
        if( s == "q" ) break;
    }
}