#include<iostream>

using namespace std;

int main(){
    int rptimes, a, b, t;
    int result[1000];
    cin >> rptimes;
    for(int i=0; i<rptimes; i++){
        cin >> a >> b;
        while(b != 0){
            t=b;
            b=a%b;
            a=t;
        }
        cout << t << endl;
    }
}
