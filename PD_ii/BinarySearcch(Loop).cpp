#include<iostream>

using namespace std;

int binarySearch(int left, int target, int right, int arr[]){
    int mid;
    while( left <= right ) {
        mid=(left+right)/2;
        if( arr[mid] == target ) return mid;
        else if( arr[mid] > target ) right=mid-1;
        else left=mid+1;
    }
    return -1;
}
int main(){
    int rptimes, index=5, target;
    int a[10];
    cin >> rptimes;
    while( rptimes-- ) {
        for(int i=0; i<10; i++){
            cin >> a[i];
        }
        cin >> target;
        cout << binarySearch(0,target,9,a)<<'\n';
    }
}
