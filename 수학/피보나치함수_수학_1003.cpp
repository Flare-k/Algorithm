#include <iostream>
#define endl "\n"
using namespace std;

int dp[41] = {0, };

int fibonacci(int n) {
    if (dp[n] > 0) {
        return dp[n];
    } 
    else {
        return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    fibonacci(40);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a == 0) {
            cout << 1 << " " << dp[a] << endl;
        } else {
            cout << dp[a - 1] << " " << dp[a] << endl;
        }
    }

   return 0;
}
