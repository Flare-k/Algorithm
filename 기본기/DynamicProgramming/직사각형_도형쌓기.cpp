#include <iostream>
using namespace std;

int dp[1001] = {0};

int divideBlock(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;

    if (dp[n] > 0) return dp[n];

    dp[n] = divideBlock(n - 1) + divideBlock(n - 2);

    return dp[n];
}

int main() {

    int n;
    cin >> n;

    cout << divideBlock(n);

    return 0;
}