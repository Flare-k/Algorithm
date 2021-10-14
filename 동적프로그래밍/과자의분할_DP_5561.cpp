#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;


int N;
// dp[n][m]: 1...n 과자 중 n을 포함해 m개 가지기 위해 필요한 최소 힘
vector<int> dp[2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    dp[0].resize(N);
    dp[1].resize(N);

    int num;
    for (int i = 1; i < N; i++) {
        cin >> num;

        for (int j = i; j > 1; j--) {
            dp[1][j] = min(dp[0][j-1], dp[0][i-(j-1)] + num);
        }

        dp[1][1] = num;
        copy(dp[1].begin(), dp[1].begin() + 1 + i, dp[0].begin());
        
    }
   
    cout << dp[0][N / 2];

    return 0;
}

