#include<bits/stdc++.h>
using namespace std;

struct node{
    char c;
    node *next;
    node( char _c ): c(_c), next(nullptr) {}
};

void Josephus(node *cur, int cnt){
    if(cur == cur->next) return;
    for(int i = 0; i < cnt-2 ; i++){
        cur = cur->next;
    }
    node *temp = cur->next;
    cur->next = temp->next;
    cout << temp->c << ' ';
    delete temp;
    Josephus(cur->next, cnt);
}

int main()
{
    int cnt = 5;
    char ch = 'A';
    node *root = new node(ch++), *cur = root;
    for( int i=0 ; i < cnt-1 ; i++ ){
        cur->next = new node(ch++);
        cur = cur->next;
    }
    cur->next = root;
    Josephus(root, 3);
}