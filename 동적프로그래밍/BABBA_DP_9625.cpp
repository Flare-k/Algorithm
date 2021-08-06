#include <iostream>
using namespace std;
/* B = BA, A = B
A
B  = 0 1
BA = 1 1
BA B = 1 2
BA B BA = 2 3
BA B BA BA B = 3 5
BA B BA BA B BA B BA = 5 8
*/

int dp[46];

int fibo(int n) {
    if (dp[n] > 0) return dp[n];

    if (n == 1 or n == 2) return 1;
    if (n > 2) dp[n] = fibo(n - 1) + fibo(n - 2);

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cout << fibo(n - 1) << ' ' << fibo(n);

    return 0;
}