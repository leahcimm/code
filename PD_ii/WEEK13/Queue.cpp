#include <iostream>

using namespace std;

class Queue
{
private:
    int Q[30];
    int head, tail;
public:
    Queue(){head=0,tail=0;}
    
    void enqueue(int val){
        Q[tail++] = val;
    }

    void dequeue(){
        head++;
    }

    void print(){
        for(int i = head; i < tail; i++){
            cout << Q[i];
            if((i+1)<tail) cout << ' ';
            else cout << "\n";
        }
    }
};

int main(){
    char b;
    int num, rptime;
    cin >> rptime;
    Queue newqueue;
    for(int i = 0; i < rptime ; i++){
        cin >> b >> num;
        if(b == 'E'){
            newqueue.enqueue(num);
        }
        if(b == 'D'){
            newqueue.dequeue();
        }
    }
    newqueue.print();
}