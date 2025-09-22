#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = INT64_MAX/3, modl=1e9+7, MAXN = 2e5;

struct LinkList {
    int val;
    LinkList *next;
    LinkList (): val(0), next(NULL) {}
    LinkList ( int _n ): val(_n), next(NULL) {}
};

void print(LinkList *root) {
    cout<<"Created Linked list is: ";
    for( ; root ; root = root->next ) cout<<' '<<root->val<<' ';
    cout<<'\n';
}

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, x, pos;
    cin>>T;
    for(;T--;) {
        char op = 'x';
        LinkList *root = new LinkList();
        for(; 1 ;) {
            cin>>op;
            if( op == 'f' ) {
                cin>>x;
                LinkList *cur = new LinkList(x);
                cur->next = root->next;
                root->next = cur;
            }
            else if( op == 'a' ) {
                cin>>x;
                LinkList *cur = root;
                for( ; cur && cur->next ; cur = cur->next );
                cur->next = new LinkList(x);
            }
            else if( op == 'i' ) {
                cin>>x>>pos;
                LinkList *cur = root;
                for( int i=0 ; i < pos && cur && cur->next ; i++ ) cur = cur->next;
                LinkList *add = new LinkList(x);
                add->next = cur->next;
                cur->next = add;
            }
            else break;
            print(root->next);
        }
        cout<<"\n";
    }
}