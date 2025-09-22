#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> degree(n+1, 0);
    for(int i = 0; i < n-1; i++) {
        int a,b; cin >> a >> b;
        degree[a]++;
        degree[b]++;
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        long long d = degree[i];
        if (d >= 2) {
            ans += d*(d-1)/2;  // C(d, 2)
        }
    }

    cout << ans << "\n";
    return 0;
}
