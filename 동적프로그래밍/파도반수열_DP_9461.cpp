#include <iostream>
using namespace std;

long long dp[101];

long long run(int n) {
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;

    while (t--) {
        cin >> n;
        cout << run(n) << '\n';
    }

    return 0;
}