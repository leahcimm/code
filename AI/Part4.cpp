#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

// def節點結構，包含狀態、g 分數、h 分數和加入順序
struct Node {
    string state;
    int g, h, order; // order 用於實現 FIFO 當 f 值相同

    Node(string s, int g_score, int h_score, int ord) 
        : state(s), g(g_score), h(h_score), order(ord) {}

    // f = g + h
    int f() const { return g + h; }
};

// 比較函數：f 值小的優先，若 f 相同則 order 小的優先
struct Compare {
    bool operator()(const Node& a, const Node& b) {
        int fa = a.f();
        int fb = b.f();
        if (fa != fb) return fa > fb; // f 值小的優先
        return a.order > b.order;     // f 相同時，order 小的優先（先進先出）
    }
};

int main() {
    priority_queue<Node, vector<Node>, Compare> pq;
    int n;
    cin >> n; 
    cin.ignore();

    int order = 0; // 用於記錄加入順序

    for (int i = 0; i < n; i++) {
        string action;
        getline(cin, action); 

        if (action == "enqueue") {
            string state;
            int g, h;
            getline(cin, state); 
            size_t pos1 = state.find(' ');
            size_t pos2 = state.rfind(' ');
            g = stoi(state.substr(pos1 + 1, pos2 - pos1 - 1));
            h = stoi(state.substr(pos2 + 1));
            state = state.substr(0, pos1); // 提取狀態
            pq.push(Node(state, g, h, order++));
            cout << "Insert OK!" << endl;
        } else if (action == "dequeue") {
            if (pq.empty()) {
                cout << "Queue is empty!!" << endl;
            } else {
                Node top = pq.top();
                pq.pop();
                cout << "Got " << top.state << endl;
            }
        }
    }

    return 0;
}