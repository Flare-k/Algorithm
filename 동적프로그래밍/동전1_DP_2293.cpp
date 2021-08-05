#include <iostream>
using namespace std;

const int MAX = 10001;
int dp[MAX] = {1, };
int coin[101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> coin[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = coin[i]; j <= K; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    cout << dp[K];

    return 0;
}