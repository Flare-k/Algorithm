#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
 
#define INF 1e9+7
#define ull unsigned long long
 
using namespace std;

int v[100010], dp[100010], n, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    dp[0] = 1;
    
    for (int i = 1; i < n; i++) {
        if (v[i] >= v[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    
    for (int i = 1; i < n; i++) {
        if (v[i] <= v[i - 1]) dp[i] = dp[i - 1] + 1;
        else dp[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    
    cout << ans;
}