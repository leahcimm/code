#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 動作的方向 and 描述
struct Action {
    int dx, dy; // 座標變化
    string desc; // 動作描述
};

const int N = 3; // 3x3 格子
const vector<Action> directions = {
    {-1, 0, "move 0 to up"},    
    {1, 0, "move 0 to down"},   
    {0, -1, "move 0 to left"},  
    {0, 1, "move 0 to right"}   
};

// 將狀態轉為 3x3 矩陣 & 找到 0 的位置
pair<vector<vector<char>>, pair<int, int>> stateToMatrix(const string& state) {
    vector<vector<char>> matrix(N, vector<char>(N));
    int x0 = -1, y0 = -1;
    for (int i = 0; i < N * N; i++) {
        int row = i / N;
        int col = i % N;
        matrix[row][col] = state[i];
        if (state[i] == '0') {
            x0 = row;
            y0 = col;
        }
    }
    return {matrix, {x0, y0}};
}

// 矩陣轉狀態字串
string matrixToState(const vector<vector<char>>& matrix) {
    string state;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            state += matrix[i][j];
        }
    }
    return state;
}

// 產生後繼狀態
void getSuccessors(const string& state) {
    // 轉為矩陣並找到 0 的位置
    auto [matrix, pos] = stateToMatrix(state);
    int x0 = pos.first;
    int y0 = pos.second;

    vector<pair<string, string>> successors; // 儲存 (動作描述 and 後繼狀態)

    // 試各方向
    for (const Action& action : directions) {
        int newX = x0 + action.dx;
        int newY = y0 + action.dy;

        // 檢查是否合法
        if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
            vector<vector<char>> newMatrix = matrix;
            swap(newMatrix[x0][y0], newMatrix[newX][newY]);
            string newState = matrixToState(newMatrix);
            successors.push_back({action.desc, newState});
        }
    }

    // output
    cout << successors.size() << endl;
    for (const auto& [desc, newState] : successors) {
        cout << desc << endl;
        cout << newState << endl;
    }
}

int main() {
    int n;
    cin >> n; // 測試案例數量
    cin.ignore(); // 清除換行符

    for (int i = 0; i < n; i++) {
        string state;
        getline(cin, state); // 讀取狀態 例 312457680
        getSuccessors(state);
    }

    return 0;
}