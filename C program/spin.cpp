#include <bits/stdc++.h>
using namespace std;

int n=3, m=3;

void print( int **arr ) {
    for( int i=0 ; i < n ; i++ ) {
        for( int j=0 ; j < m ; j++ ) {
            cout<<arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

void spin( int **arr, int N ) {
    int t[N][N];
    for( int i=0 ; i < N ; i++ ) for( int j=0 ; j < N ; j++ ) t[i][j]=arr[i][j];
    for( int i=0 ; i < N ; i++ ) for( int j=0 ; j < N ; j++ ) arr[j][N-i-1]=t[i][j];
    for( int i=0 ; i < N ; i++ ) for( int j=0 ; j < N ; j++ ) arr[j][N-i-1]=t[i][j];
    for( int i=0 ; i < N ; i++ ) for( int j=0 ; j < N ; j++ ) arr[j][N-i-1]=t[i][j];

}
/*
void re(int x,int y,int k){
    bool a[10][10];
    for(int i = 0;i < k;i++){
        for(int j = 0;j < k;j++){
            a[x+i][y+j] = arr[x+i][y+j];
        }
    }
    for(int i = 0;i < k;i++){
        for(int j = 0;j < k;j++){
            arr[x+j][y+k-i-1] = a[x+i][y+j];
        }
    }
    for(int i = 0;i < k;i++){
        for(int j = 0;j < k;j++){
            arr[x+j][y+k-i-1] = a[x+i][y+j];
        }
    }
    for(int i = 0;i < k;i++){
        for(int j = 0;j < k;j++){
            arr[x+j][y+k-i-1] = a[x+i][y+j];
        }
    }
}
*/

int main()
{
    int **A=new int*[n], **B=new int*[n];
    int An=0, Bn=0;
    for( int i=0 ; i < n ; i++ ) A[i]=new int[m], B[i]=new int[m];
    for( int i=0 ; i < n ; i++ ) for( int j=0 ; j < m ; j++ ) cin>>A[i][j];
    print(A);
    spin(A,n);
    print(A);
}