#include<iostream>

using namespace std;

int binarySearch(int left, int target, int right, int a[]){
    int mid = (left + right)/2;
    if(left <= right) {
        if(a[mid] == target) return mid;
        else if(a[mid] < target) return binarySearch(mid+1, target, right, a);
        else return binarySearch(left, target, mid-1, a);
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
        cout << binarySearch(0, target,9,a)<<'\n';
    }
}
