#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n; // 讀取操作數量
    vector<int> baozi; // 存放包子的重量
    int count = 1; // 計數器，初始為 1
    vector<string> results; // 儲存結果

    for (int i = 0; i < n; ++i) {
        string operation;
        cin >> operation; // 讀取操作

        if (operation == "DIOU") {
            int x;
            cin >> x; // 讀取包子重量
            baozi.push_back(x); // 將包子重量加入向量
        } else if (operation == "MUMIMUMI") {
            if (count <= 0 || count > baozi.size()) {
                results.push_back("BAONU"); // 輸出 BAONU
            } else {
                sort(baozi.begin(), baozi.end()); // 排序包子重量
                results.push_back(to_string(baozi[baozi.size() - count])); // 輸出第 count 大的重量
                count++; // 計數器加一
            }
        } else if (operation == "<3DONGDONG") {
            if (count <= 0 || count > baozi.size()) {
                results.push_back("BAONU"); // 輸出 BAONU
            } else {
                sort(baozi.begin(), baozi.end()); // 排序包子重量
                results.push_back(to_string(baozi[baozi.size() - count])); // 輸出第 count 大的重量
                count--; // 計數器減一
            }
        }
    }

    for (const string& result : results) {
        cout << result << endl; // 輸出所有結果
    }

    return 0;
}