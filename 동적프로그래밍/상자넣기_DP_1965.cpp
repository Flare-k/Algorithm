#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// LIS + DP
// Longest Increasing Subsequence

int arr[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    int maxCnt = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }

        maxCnt = max(maxCnt, dp[i]);
    }

   cout << maxCnt;

    return 0;
}
