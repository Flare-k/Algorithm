#include <iostream>
using namespace std;

const int MAX = 91;
long long dp[MAX];

long long fibo(int n) {
    if (dp[n] > 0) return dp[n];

    if (n == 1 || n == 2) return 1;
    if (n > 2) dp[n] = fibo(n-1) + fibo(n-2);

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cout << fibo(n);

    return 0;
}