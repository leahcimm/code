#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e2 + 1;

struct node {
    int x, y, n;
    node *next;
    node(int _n, int _x, int _y): n(_n), x(_x), y(_y), next(NULL) {}
};

struct spmatrix {
    int m, n;
    node **row;
    node **col;
    spmatrix( int _m, int _n, array<array<int, MAXN>,MAXN> arr): m(_m), n(_n){
        row = new node*[m];
        col = new node*[n];
        for(int i=0; i<m; i++){
            row[i] = new node(0, -1, -1);
            node *tmp = row[i];
            for(int j=0; j<n; j++){
                if( arr[i][j]) {
                    tmp->next = new node (arr[i][j], i, j);
                    tmp = tmp->next;
                }
            }
        }
        for(int i=0; i<n; i++){
            col[i]= new node(0, -1, -1);
            node *tmp = col[i];
            for(int j = 0; j < m; j++ ){
                if( arr[j][i]) {
                    tmp->next = new node (arr[j][i], j, i);
                    tmp = tmp->next;
                }
            }
        }
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    array<array<int,MAXN>,MAXN> arr;
    for(int i=0; i<m; i++) for(int j=0; j<n; j++) cin >> arr[i][j];
    spmatrix *sp= new spmatrix(m, n, arr);
}