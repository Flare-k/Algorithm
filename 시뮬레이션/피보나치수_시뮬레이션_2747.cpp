#include <iostream>

using namespace std;

const int MAX = 46;

int dp[MAX];

int fibo(int n) {
    if (dp[n] > 0)
        return dp[n];

    if (n == 0) 
        return 0;
    if (n == 1 || n == 2) 
        return 1;

    if (n > 2) {
        dp[n] = fibo(n - 1) + fibo(n - 2);
    }

    return dp[n];

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << fibo(n);

    return 0;
}