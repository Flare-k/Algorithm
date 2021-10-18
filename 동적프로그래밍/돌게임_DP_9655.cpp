#include <iostream>
#include <algorithm>
using namespace std;

// DP로 풀이
int N;
int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 1;

    for (int i = 4; i <= N; i++) {
        dp[i] = min(dp[i-3] + 1, dp[i-1] + 1);
    }

    if (dp[N] % 2) cout << "SK";
    else cout << "CY";

    return 0;
}

/*
// 수식으로 풀이
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin>> N;

    cout << (N % 2 ? "SK" : "CY");

    return 0;
}
*/