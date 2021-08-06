#include <iostream>
using namespace std;

int dp[51][51][51];

int w(int a, int b, int c) {
    if (a <= 0 or b <= 0 or c <= 0) return 1;

    if (dp[a][b][c] > 0) return dp[a][b][c];     // memoization 필수!

    if (a > 20 or b > 20 or c > 20) return w(20, 20, 20);
    if (a < b && b < c) return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c) - w(a, b - 1, c);
    else dp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);

    return dp[a][b][c];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;

        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
    }

    return 0;
}