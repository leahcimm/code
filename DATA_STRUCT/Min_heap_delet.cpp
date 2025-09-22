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
        
    }
    for(int i=1 ; i < last ; i++) cout << "[" << i << "]" << tree[i] << ' ';
    cout << '\n';
    while( last > 1 ){
        int p=1; 
        tree[p]=tree[last-1];
        last--;
        while(2*p < last){
            int j= 2*p;
            if(j+1<last && tree[p*2]>tree[p*2+1]) j++;
            if(tree[p] <= tree[j]) break;
            swap(tree[p], tree[j]), p = j;
        }
        for(int i=1 ; i < last ; i++) cout << "[" << i << "]" << tree[i] << ' ';
        cout << '\n';
        //for(int i=1 ; i < last ; i++) cout << "[" << i << "]" << tree[i] << " \n"[i+1 == last];
    }
}