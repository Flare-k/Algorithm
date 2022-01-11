#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100001;
int N, K;
int dp[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    
    vector<int> coins(N, 0);
    fill(dp, dp + MAX, 21e8);

    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    for (int coin : coins) {
        if (coin > K) continue;
        dp[coin] = 1;
        for (int j = coin + 1; j <= K; j++) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    if (dp[K] == 21e8) dp[K] = -1;

    cout << dp[K];

    return 0;
}