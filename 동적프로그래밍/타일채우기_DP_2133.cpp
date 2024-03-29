#include <iostream>
using namespace std;

int N;
int dp[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= N; i += 2) {
        dp[i] = 3 * dp[i - 2];
        for (int j = 4; j <= i; j += 2) {
            dp[i] += 2 * dp[i - j];
        }
    }

    cout << dp[N];

    return 0;
}