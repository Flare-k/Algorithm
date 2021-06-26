#include <iostream>
using namespace std;

int target, cnt;
long long dp[201][201];   // dp[a][b] = a개로 b 만들기 = 개수

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> target >> cnt;

    // 자명해 구하기
    for (int i = 0; i <= target; i++) {
        dp[1][i] = 1;
        dp[2][i] = i + 1;
    }

    for (int i = 3; i <= cnt; i++) {
        for (int j = 0; j <= target; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000000;
            }
        }
    }

    cout << dp[cnt][target]%1000000000 << '\n';

    return 0;
}