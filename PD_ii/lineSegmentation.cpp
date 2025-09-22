#include<iostream>

using namespace std;

int main(){
    int i, input, cOunt=0, temp=1;
    while(cin >> input){
        cOunt=0;
        for(i=1; input >= temp; i++){
            input = input - i;
            temp = i;
            cOunt++;
        }
        cout << cOunt << endl;
    }
}
