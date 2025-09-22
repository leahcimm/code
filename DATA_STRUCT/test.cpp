#include<iostream>
using namespace std;

int main()
{
    int number, last=1;
    int tree[100];
    while(cin >> number){
        int p=last++;
        tree[p]=number;
        while(p>1 && tree[p]<tree[p/2]) swap(tree[p], tree[p/2]), p=p/2;
    }
    while(last>1){
        int p=1;
        tree[p]=tree[last-1];
        last--;
    }
}