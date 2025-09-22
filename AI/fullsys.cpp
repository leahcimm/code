#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

const int N = 3; // 3x3 格子
const string GOAL = "012345678"; // goal state

// 動作結構
struct Action {
    int dx, dy;
    string desc;
};
const vector<Action> directions = {
    {-1, 0, "move 0 to up"},    // 上
    {1, 0, "move 0 to down"},   // 下
    {0, -1, "move 0 to left"},  // 左
    {0, 1, "move 0 to right"}   // 右
};

// 節點結構
struct DataNode {
    string state;
    int g, h, action; // action: 動作索引 (-1 表示無動作)
    DataNode* parent;

    DataNode(string s, int g_score, int h_score, int act = -1, DataNode* p = nullptr)
        : state(s), g(g_score), h(h_score), action(act), parent(p) {}

    int f() const { return g + h; }
};

// priQueue比較器
struct Compare {
    bool operator()(const DataNode* a, const DataNode* b) {
        int fa = a->f(), fb = b->f();
        return fa > fb; // f 值小的優先
    }
};

// Part I: 檢查是否可解
int countInversions(const string& state) {
    vector<int> nums;
    for (char c : state) {
        if (c != '0') nums.push_back(c - '0');
    }
    int inversions = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) inversions++;
        }
    }
    return inversions;
}

bool unsolvable(const string& state) {
    return countInversions(state) % 2 != 0; // n=3，亂序對數為奇數則不可解
}

// Part II: 生成後繼state
pair<vector<string>, vector<int>> findSuccessors(const string& state) {
    vector<vector<char>> matrix(N, vector<char>(N));
    int x0 = -1, y0 = -1;
    for (int i = 0; i < N * N; i++) {
        int row = i / N, col = i % N;
        matrix[row][col] = state[i];
        if (state[i] == '0') {
            x0 = row;
            y0 = col;
        }
    }

    vector<string> nextStates;
    vector<int> actions;
    for (int i = 0; i < directions.size(); i++) {
        const Action& action = directions[i];
        int newX = x0 + action.dx;
        int newY = y0 + action.dy;
        if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
            vector<vector<char>> newMatrix = matrix;
            swap(newMatrix[x0][y0], newMatrix[newX][newY]);
            string newState;
            for (int r = 0; r < N; r++) {
                for (int c = 0; c < N; c++) {
                    newState += newMatrix[r][c];
                }
            }
            nextStates.push_back(newState);
            actions.push_back(i);
        }
    }
    return {nextStates, actions};
}

// Part III: 計算曼哈頓距離
int heuristic(const string& state) {
    int distance = 0;
    for (int i = 0; i < N * N; i++) {
        if (state[i] != '0') {
            int currRow = i / N, currCol = i % N;
            int num = state[i] - '0';
            int goalRow = num / N, goalCol = num % N;
            distance += abs(currRow - goalRow) + abs(currCol - goalCol);
        }
    }
    return distance;
}

// 主程式
void solvePuzzle(const string& initialState) {
    // 檢查是否可解
    if (unsolvable(initialState)) {
        cout << "No solution!!" << endl;
        return;
    }
    // 檢查是否已是目標狀態
    if (initialState == GOAL) {
        cout << "It is the goal state." << endl;
        return;
    }

    priority_queue<DataNode*, vector<DataNode*>, Compare> pqueue;
    unordered_set<string> visited; // 記錄已訪問的state

    DataNode* root = new DataNode(initialState, 0, heuristic(initialState));
    pqueue.push(root);
    visited.insert(initialState);

    DataNode* final = nullptr;
    while (!pqueue.empty()) {
        DataNode* current = pqueue.top();
        pqueue.pop();

        if (current->state == GOAL) {
            final = current;
            break;
        }

        auto [nextStates, actions] = findSuccessors(current->state);
        for (int i = 0; i < nextStates.size(); i++) {
            const string& nextState = nextStates[i];
            if (visited.find(nextState) == visited.end()) {
                DataNode* newNode = new DataNode(nextState, current->g + 1, heuristic(nextState), actions[i], current);
                pqueue.push(newNode);
                visited.insert(nextState);
            }
        }
    }

    if (final == nullptr) {
        cout << "No solution!!" << endl;
    } else {
        // 反向追蹤動作
        vector<string> solution;
        DataNode* node = final;
        while (node->parent != nullptr) {
            solution.push_back(directions[node->action].desc);
            node = node->parent;
        }
        // 從初始狀態到目標狀態 逆序輸出
        for (int i = solution.size() - 1; i >= 0; i--) {
            cout << solution[i] << endl;
        }
    }

    // 清ram
    while (!pqueue.empty()) {
        delete pqueue.top();
        pqueue.pop();
    }
    delete final;
}

int main() {
    string initialState;
    getline(cin, initialState); // 讀初始state
    solvePuzzle(initialState);
    return 0;
}