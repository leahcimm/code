#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s; cin >> s;

    // 記錄每個字元最後出現的位置
    vector<int> lastPos(26, -1);
    for (int i = 0; i < (int)s.size(); i++) {
        lastPos[s[i]-'a'] = i;
    }

    vector<int> result;
    int start = 0, end = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        end = max(end, lastPos[s[i]-'a']);
        if (i == end) {
            result.push_back(end - start + 1);
            start = i + 1;
        }
    }

    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i];
        if (i < (int)result.size()-1) cout << " ";
    }
    cout << "\n";

    return 0;
}
