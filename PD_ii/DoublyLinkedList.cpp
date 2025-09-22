#include<iostream>
#include<memory>
using namespace std;

struct linkList{
    int x;
    linkList *pre, *next;
};



int main(){
    linkList *head=new linkList, *tail=head;
    int temp;
    while(cin >> temp){
        linkList *ptr=new linkList;
        ptr->x = temp;
        ptr->pre = tail;
        tail->next = ptr;
        tail = ptr;
    }
}
