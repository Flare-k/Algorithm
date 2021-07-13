#include <iostream>
#include <algorithm>
using namespace std;

/* 
    LIS
    가장 큰 증가하는 부분수열
*/

int arr[201];
int dp[201];

int LIS(int n) {
    int maxElem = -21e8;

    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j <= i; j++) {
            if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        maxElem = max(maxElem, dp[i]);
    }

    return n - maxElem;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int num;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        arr[i] = num;
    }

    cout << LIS(n) << '\n';

    return 0;
}