#include<iostream>
#include<sstream>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;
 
void readInput(vector<int> & v) {
    string line, token;
    getline(cin, line);
    stringstream ss(line);
 
    int count = 0;
    while (getline(ss, token, ' ')) {
        v.push_back(stoi(token));
    }
}
 
void printVector(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i == v.size()-1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}
 
void mergeSort( vector<int> &arr, int L, int R ) { //[L,R)
    if( L+1 >= R ) return;
    int mid=(L+R)/2;
    mergeSort(arr,L,mid);
    mergeSort(arr,mid,R);
    vector<int> temp=arr;
    reverse(temp.begin()+mid,temp.begin()+R);
    int l=L, r=R-1,  ptr=L;
    while( l <= r ) {
        if( temp[l] < temp[r] ) arr[ptr++]=temp[l++];
        else arr[ptr++]=temp[r--];
    }
}
 
void mergeSort(vector<int> &v) {
    mergeSort(v,0,v.size());
}
 
int main() {
    vector<int> v;
    readInput(v);
    mergeSort(v);
    printVector(v);
}