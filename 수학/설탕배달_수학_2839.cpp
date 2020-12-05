#include <algorithm>
#include <iostream>
using namespace std;

int dp[5000];

int getSugar(int n) {
    if (dp[n] > 0) return dp[n];
    
    for (int i = 0; i <= n; i++) 
        dp[i] = 2222;
    
    dp[3] = 1;
    dp[5] = 1;

    for (int i = 6; i <= n; i++)
        dp[i] = min(dp[i - 3], dp[i - 5]) + 1;

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int sugar;
    cin >> sugar;

    if (getSugar(sugar) >= 2222)
        cout << -1 << endl;
    else
        cout << getSugar(sugar) << endl;

    return 0;
}
