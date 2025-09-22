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
    for( ; head ; head = head->next ) cout << head->val << ' ';
    cout << '\n';
}

LinkList* sum( LinkList *A, LinkList *B ) {
    LinkList *head = new LinkList(0), *cur = head;
    int carry = 0;
    for( ; A || B || carry ; cur = cur->next ) {
        if( A ) carry += A->val, A = A->next;
        if( B ) carry += B->val, B = B->next;
        cur->next = new LinkList(carry%10);
        carry /= 10;
    }
    return head->next;
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x;
    LinkList *A = new LinkList(0), *B = new LinkList(0), *cur;
    stringstream ss;
    string s;
    getline(cin, s); ss << s;
    for( cur = A ; ss >> x ; cur = cur->next ) cur->next = new LinkList(x);
    ss.str(""); ss.clear(); getline(cin, s); ss << s;
    for( cur = B ; ss >> x ; cur = cur->next ) cur->next = new LinkList(x);
    print(sum(A->next, B->next));
}