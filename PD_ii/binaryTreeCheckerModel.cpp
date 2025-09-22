#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> arr;
    int num;

    while(cin>>num) arr.push_back(num);

    int sz = arr.size();

    for(int i = 1; i < sz; i++){
        if(arr[i] > 0 && arr[(i-1)/2] == -1){
            cout<<"false\n"; return 0;
        }
    }

    cout<<"true\n";
    return 0;
}
