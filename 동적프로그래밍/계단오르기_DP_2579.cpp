#include <iostream>
#include <algorithm>
using namespace std;

int T;;
const int MAX = 301;
int dp[MAX];
int stair[MAX];

int run(int n) {
    if (n == 0) return 0;
    if (n == 1) return dp[n] = stair[1];
    if (n == 2) return dp[n] = stair[1] + stair[2];

    if (dp[n] > 0) return dp[n];

    dp[n] = max(stair[n] + run(n - 2), stair[n] + stair[n - 1] + run(n - 3));

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    for(int i = 1; i <= T; i++) {
        cin >> stair[i];
    }

    run(T);

    cout << dp[T];

    return 0;
}