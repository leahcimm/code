#include <bits/stdc++.h>
using namespace std;

int n, m;

void spin( int **arr, int N ) {
    int t[N][N];
    for( int i=0 ; i < N ; i++ ) for( int j=0 ; j < N ; j++ ) t[j][N-i-1]=arr[i][j];
    for( int i=0 ; i < N ; i++ ) for( int j=0 ; j < N ; j++ ) arr[i][j]=t[i][j];
}

bool check( int **A, int **B ) {
    for( int i=0 ; i < n ; i++ ) for( int j=0 ; j < m ; j++ ) if( A[i][j] != B[i][j] ) return 0;
    return 1;
}

int main()
{
    int times;
    cin>>times;
    while(times--) {
        cin>>n>>m;
        int **A=new int*[n], **B=new int*[n];
        int An=0, Bn=0, flag=1;
        for( int i=0 ; i < n ; i++ ) A[i]=new int[m], B[i]=new int[m];
        for( int i=0 ; i < n ; i++ ) for( int j=0 ; j < m ; j++ ) cin>>A[i][j];
        for( int i=0 ; i < n ; i++ ) for( int j=0 ; j < m ; j++ ) cin>>B[i][j];
        
        if( n == 1 or m == 1 ) {
            if( check(A,B) ) {
                flag=0;
            }
        }
        else if( n == 2 and m == 2 ) {
            for( int i=0 ; i < 4 ; i++ ) {
                spin(A,2);
                if( check(A,B) ) {
                    flag=0;
                }
            }
        }
        else {
            for( int i=0 ; i < n ; i++ ) 
                for( int j=0 ; j < m ; j++ ) {
                    if( A[i][j] ) An++;
                    if( B[i][j] ) Bn++;
                }
            if( An == Bn ) {
                flag=0;
            }
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
}