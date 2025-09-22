#include<iostream>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int rptimes, x, y;
    int result[1000];
    cin >> rptimes;
    for(int i=0; i<rptimes; i++){
        cin >> x >> y;
        result[i] = gcd(x, y);
    }
    for(int i=0; i<rptimes; i++){
        cout << result[i] << endl;
    }
}
