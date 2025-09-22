#include <iostream>
using namespace std;

template<typename tn> 
class stack {
private:
    tn arr[100];
    int ptr;
public:
    stack() {
        ptr=0;
    }
    void push( tn a ) {
        arr[ptr++]=a;
    }
    int size() {
        return ptr;
    }
    void pop() {
        ptr--;
    }
    tn top() {
        if( ptr > 0 ) return arr[ptr-1];
        return-1;
    }
};


int main()
{
    stack<double> st;
    st.push(1.5);
    st.push('d');
    st.pop();
    cout<<st.top();
}