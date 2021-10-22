#include <iostream>
#include <cstring>
using namespace std;

int T, N;
const int MAX = 501;
int pages[MAX];
int sum[MAX];
int dp[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> T;

    while (T--) {
        memset(pages, 0, sizeof(pages));
        memset(sum, 0, sizeof(sum));
        memset(dp, 0, sizeof(dp));

        cin >> N;

        for (int i = 1; i <= N; i++) {
            cin >> pages[i];
            sum[i] = sum[i - 1] + pages[i];
        }

        for (int i = 1; i < N; i++) {
            for (int x = 1; x + i <= N; ++x) {
                int y = x + i;
                dp[x][y] = 2e9;

                for (int m = x; m < y; ++m) {
                    dp[x][y] = min(dp[x][y], dp[x][m] + dp[m + 1][y] + sum[y] - sum[x - 1]);
                }
            }
        }

        cout << dp[1][N] << '\n';
    }


    return 0;
}