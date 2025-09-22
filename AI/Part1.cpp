#include <iostream>
#include <string>
#include <vector>

using namespace std;

int countInversions(const string& state) {
    vector<int> nums;
    for (char c : state) {
        if (c != '0') {
            nums.push_back(c - '0'); // 將字符轉為整數
        }
    }
    int inversions = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] > nums[j]) {
                inversions++;
            }
        }
    }
    return inversions;
}

// 判斷是否可解
bool isSolvable(const string& state) {
    int inversions = countInversions(state);
    // n = 3（奇數），亂序對數為偶數則可解
    return (inversions % 2 == 0);
}

int main() {
    int n;
    cin >> n; // 測試案例數量
    cin.ignore(); // 清除換行符號

    for (int i = 0; i < n; i++) {
        string state;
        getline(cin, state); // 讀取狀態 例如 {312457680}
        if (isSolvable(state)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}