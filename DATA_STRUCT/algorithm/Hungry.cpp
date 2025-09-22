#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, H, B, D;
    cin >> n >> H >> B >> D;

    vector<int> h(n+1), c(n+1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    // dp[i][f]: 遇完第 i 條龍，且食物量為 f 時的最大獲利
    // 使用滾動陣列: dpCurr, dpPrev
    vector<long long> dpPrev(B+1, -1), dpCurr(B+1, -1);

    dpPrev[H] = 0; // 初始狀態

    for (int i = 1; i <= n; i++) {
        for (int f = 0; f <= B; f++)
            dpCurr[f] = -1; // 重置當前列

        for (int f = 0; f <= B; f++) {
            if (dpPrev[f] == -1) continue; // 不可達狀態

            // 選擇採食
            int newFood = min(B, f + D);
            dpCurr[newFood] = max(dpCurr[newFood], dpPrev[f]);

            // 選擇餵食（若可行）
            if (f >= h[i]) {
                int newFood2 = f - h[i];
                dpCurr[newFood2] = max(dpCurr[newFood2], dpPrev[f] + c[i]);
            }
        }

        dpPrev.swap(dpCurr);
    }

    long long ans = 0;
    for (int f = 0; f <= B; f++) {
        ans = max(ans, dpPrev[f]);
    }

    cout << ans << "\n";
    return 0;
}
