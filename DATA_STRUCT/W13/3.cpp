#include <bits/stdc++.h>
#define int long long
#define cl(x) (x*2)
#define cr(x) (x*2+1)
using namespace std;
 
const int INF = INT64_MAX/3, modl=1e9+7, MAXN = 2e5;

struct MinHeap {
    int heap[MAXN], sz;
    MinHeap() { sz = 0; }
    void push(int x) {
        heap[++sz] = x;
        int i = sz;
        while( i > 1 && heap[i] < heap[i>>1] ) {
            swap(heap[i], heap[i>>1]);
            i /= 2;
        }
    }
    int pop() {
        int ret = heap[1];
        heap[1] = heap[sz--];
        int i = 1;
        while( i*2 <= sz ) {
            int j = i*2;
            if( j+1 <= sz && heap[j+1] < heap[j] ) j++;
            if( heap[i] < heap[j] ) break;
            swap(heap[i], heap[j]);
            i = j;
        }
        return ret;
    }
    int top() { return heap[1]; }
    int size() { return sz; }
    bool empty() { return sz == 0; }
    void print() {
        for(int i = 1; i <= sz; i++) cout << "[" << i << "]" << heap[i] << " ";
        cout << '\n';
    }
    int minheight( int x=1 ) {
        if( x > sz ) return 0;
        return min( minheight(cl(x)), minheight(cr(x)) ) + 1;
    }
};


signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    MinHeap h;
    for(; cin >> t ;) h.push(t);
    cout << h.minheight() << '\n';
}