#include <iostream>
#include <vector>
using namespace std;

// Dynamic programming으로 풀이하기
int n, k;
vector<int> dp[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    dp[1].resize(1);
    dp[1][0] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i].resize(i);
        dp[i][0] = 1;
        dp[i][i - 1] = 1;

        for (int j = 0; j < i-2; j++) {
            dp[i][j+1] = dp[i-1][j] + dp[i-1][j+1];
        }
    }

    cout << dp[n][k - 1];

    return 0;
}