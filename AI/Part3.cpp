#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int N = 3; // 3x3 格子
const string GOAL = "012345678"; // 目標

// 將數字轉為目標位置的座標
pair<int, int> getGoalPosition(char digit) {
    int num = digit - '0';
    return {num / N, num % N}; // goal's row and 列
}

// 曼哈頓dis
int manhattanDistance(const string& state) {
    int distance = 0;
    for (int i = 0; i < N * N; i++) {
        if (state[i] != '0') {
            int currRow = i / N;
            int currCol = i % N;
            auto [goalRow, goalCol] = getGoalPosition(state[i]);
            // 計算當前位置到目標位置的曼哈頓距離
            distance += abs(currRow - goalRow) + abs(currCol - goalCol);
        }
    }
    return distance;
}

int main() {
    int n;
    cin >> n; 
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string state;
        getline(cin, state);
        cout << manhattanDistance(state) << endl;
    }

    return 0;
}