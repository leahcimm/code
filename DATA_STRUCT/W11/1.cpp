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

void print(LinkList *head) {
    for( ; head ; head = head->next ) cout << head->val << ' ';
    cout << '\n';
}

void reverse(LinkList *head) {
    LinkList *pre = NULL, *cur = head, *nxt = head->next;
    for( ; cur ; ) {
        cur->next = pre;
        pre = cur;
        cur = nxt;
        if(nxt) nxt = nxt->next;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    LinkList *head = new LinkList(0), *cur = head;
    int t;
    for( ; cin >> t ; cur = cur->next ) cur->next = new LinkList(t);
    reverse(head->next);
    print(cur);   
}