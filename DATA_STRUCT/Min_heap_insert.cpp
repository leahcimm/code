#include <bits/stdc++.h>
using namespace std;

int main()
{
    int number, last=1;
    int tree[100];
    while(cin >> number){
        int p = last++;
        tree[p]=number;
        while(p > 1 && tree[p]<tree[p/2]) swap(tree[p], tree[p/2]), p = p/2;
        for( int i=1 ; i < last ; i++ ) cout << "[" << i << "]" << tree[i] << ' ';
        cout << '\n';
    }
}