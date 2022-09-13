#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int ans;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int s1Len = s1.length();
    int s2Len = s2.length();

    vector<vector<int>> dp(s2Len, vector<int>(s1Len, 0));
    // dp[s2][s1]

    for (int i = 0; i < s2Len; i++) {
        for (int j = 0; j < s1Len; j++) {
            if (s2[i] == s1[j]) {
                dp[i][j] = 1;
                if (i >= 1 && j >= 1) dp[i][j] += dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
        }
    }

    cout << ans;

    return 0;
}