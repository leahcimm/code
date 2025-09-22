#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

const int N = 3; // 3x3 格子
const string GOAL = "012345678"; // 目標狀態

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
    vector<int> path; // 儲存動作序列

    DataNode(string s, int g_score, int h_score, int act = -1)
        : state(s), g(g_score), h(h_score), action(act) {}

    int f() const { return g + h; }
};

// priqueue比較器
struct Compare {
    bool operator()(const DataNode& a, const DataNode& b) {
        int fa = a.f(), fb = b.f();
        if (fa != fb) return fa > fb; // f 值小的優先
        return a.g < b.g; // f 相同時，g 大的優先（後加入的節點）
    }
};

// Part I: 檢查是否可解
int countInversions(const string& state) {
    vector<int> nums;
    for (char c : state) {
        if (c != '0') nums.push_back(c - '0');
    }
    int inversions = 0;
    for (size_t i = 0; i < nums.size(); i++) {
        for (size_t j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) inversions++;
        }
    }
    return inversions;
}

bool unsolvable(const string& state) {
    return countInversions(state) % 2 != 0; // n=3，亂序對數為奇數則不可解
}

// Part II: 生成後繼狀態
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
    for (size_t i = 0; i < directions.size(); i++) {
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

    priority_queue<DataNode, vector<DataNode>, Compare> pqueue;
    unordered_set<string> visited;

    DataNode root(initialState, 0, heuristic(initialState));
    pqueue.push(root);

    DataNode finalNode = root;
    bool found = false;

    while (!pqueue.empty()) {
        DataNode current = pqueue.top();
        pqueue.pop();

        if (current.state == GOAL) {
            finalNode = current;
            found = true;
            break;
        }

        if (visited.find(current.state) != visited.end()) continue;
        visited.insert(current.state);

        auto [nextStates, actions] = findSuccessors(current.state);
        for (size_t i = 0; i < nextStates.size(); i++) {
            const string& nextState = nextStates[i];
            DataNode newNode(nextState, current.g + 1, heuristic(nextState), actions[i]);
            newNode.path = current.path;
            newNode.path.push_back(actions[i]);
            pqueue.push(newNode);
        }
    }

    if (!found) {
        cout << "No solution!!" << endl;
    } else {
        for (int action : finalNode.path) {
            cout << directions[action].desc << endl;
        }
    }
}


bool isValidState(const string& state) {
    if (state.length() != 9) return false;
    vector<bool> seen(9, false);
    for (char c : state) {
        if (c < '0' || c > '8') return false;
        int num = c - '0';
        if (seen[num]) return false; 
        seen[num] = true;
    }
    return true;
}

int main() {
    string initialState;
    getline(cin, initialState);
    if (!isValidState(initialState)) {
        cout << "Invalid input state!!" << endl;
        return 0;
    }
    solvePuzzle(initialState);
    return 0;
}