#include <iostream>
#include<vector>
using namespace std;

template<int a> 
int f() { return a; }



void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp; 
}

int main()
{
    
    vector<int> vc;
    for(int i = 0, c; i < 10; i++){
        cin>>c; vc.push_back(c);
    }

    int N = 10;
    

    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < N-1; j++){
            if(vc[j] > vc[j+1]) {
                swap(vc[j], vc[j+1]);
            }
        }
    }

    for(int i : vc) cout<<i<<' ';
}