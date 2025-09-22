#include <bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;

const int INF = INT64_MAX/3, modl=1e9+7, MAXN = 1e6+5;

struct LinkList {
    int val;
    LinkList *next;
    LinkList(int x) : val(x), next(NULL) {}
};

void print( LinkList *head ) {
    for( ; head ; head = head->next ) cout << head->val << ',';
    cout << '\n';
}

void insert( LinkList *head, int val ) {
    for( ; head ; head = head->next ) {
        if( !head->next ) {
            head->next = new LinkList(val);
            return;
        }
        else if( head->next->val > val ) {
            LinkList *tmp = head->next;
            head->next = new LinkList(val);
            head->next->next = tmp;
            return;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, t;
    string s;
    unordered_map<string,LinkList*> mp;
    vector<string> v;
    cin >> n;
    for( int i=0 ; i < n ; i++ ) {
        cin >> s >> t;
        if( !mp[s] ) mp[s] = new LinkList(0), v.push_back(s);
        insert(mp[s], t);
    }
    for( auto i : v ) {
        cout << i << ',';
        print(mp[i]->next);
    }
}