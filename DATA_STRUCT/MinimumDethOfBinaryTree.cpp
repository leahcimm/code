#include <bits/stdc++.h>
using namespace std;

int MinDeth(int *tree){
    int p=1;
    if(!tree[p]) return 0;
    if(!tree[p])
}

int main()
{
    int number, index=1, last=1;
    int tree[100];
    while(cin >> number){
        int p = last++;
        tree[p]=number;
        while(p > 1 && tree[p]<tree[p/2]) swap(tree[p], tree[p/2]), p = p/2;
    }
    cout << MinDeth(tree);
}