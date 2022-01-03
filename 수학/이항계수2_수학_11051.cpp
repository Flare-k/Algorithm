#include <iostream>
using namespace std;

// nCr = n-1Cr-1 + n-1Cr
int N, K, A, B;
const int MAX = 10007;
int dp[1001][1001];

int run(int n, int r) {
    if (n < r) return 0;
    if (r == 0) return 1;

    if (dp[n][r] > 0) return dp[n][r];

    dp[n][r] = (run(n - 1, r) % MAX + run(n - 1, r - 1) % MAX) % MAX;

    return dp[n][r];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[2][1] = 2;
    dp[2][2] = 1;

    cout << run(N, K);

    return 0;
}