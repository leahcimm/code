#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int maxi( vector<int>& arr, int L, int R ) { //[L,R]
    if( R <= L ) return arr[L];
    int mid=(L+R)/2;
    return max(maxi(arr,L,mid),maxi(arr,mid+1,R));
}

int main(){
    vector<int> arr;//vector是容器
    int arra;
    while (cin >> arra) {
        arr.push_back(arra);
    }

    cout<<maxi(arr,0,arr.size())<<"\n";
}