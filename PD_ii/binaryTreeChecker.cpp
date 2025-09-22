#include<iostream>

using namespace std;

int main(){
    int minusOne, Vals;
    int arr[16];// check[]={1,2,3,4,6,7,5,8,10,12,14,15,13,11,9};
    for(int i = 1; i<16; i++){
        cin >> arr[i];
    }
    for(int i = 1; i<16; i++){
        if(arr[i] == -1) minusOne++;
    }
    Vals = 15 - minusOne;
    if(Vals == 0){
        cout << "false" <<endl;
    }
    else{
        for(int i = Vals; i>0; i--){
            if(arr[i] == -1) break;
        }
    }
}
