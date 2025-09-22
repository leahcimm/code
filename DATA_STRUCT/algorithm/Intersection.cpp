#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        long long x0, y0, r, a, b, c;
        cin >> x0 >> y0 >> r >> a >> b >> c;
        
        // 計算距離
        double distance = abs(a * x0 + b * y0 - c) / sqrt(a * a + b * b);
        
        // 判斷交點數量
        if (distance < r) {
            cout << 2 << endl;  // 兩個交點
        } else if (distance == r) {
            cout << 1 << endl;  // 一個交點
        } else {
            cout << 0 << endl;  // 無交點
        }
    }
    
    return 0;
}
