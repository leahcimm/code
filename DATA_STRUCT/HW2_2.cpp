#include<bits/stdc++.h>
using namespace std;

struct node{
    int n;
    node *next;
    node(int _n):n(_n), next(NULL) {}
};
node *L, *P;

void moveR(node *head, int n){
    if(!head || !n) return L=head, void();
    cout << head->n << ' ';
    moveR(head->next, n-1);
}

void moveL(node *head, int n){
        if(!head || !n) return P=head, void();
        cout << head->n << ' ';
        moveL(head->next, n-1);
    };

int main()
{
    int n = 5;
    moveR(P, n);
    moveL(L, n);
}