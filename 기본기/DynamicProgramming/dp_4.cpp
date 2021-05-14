#include <iostream>
using namespace std;

int dp[1001];

int run(int value) {
    if (value == 0) return 0;
    if (value == 1) return 1;

    if (dp[value] > 0) return dp[value];

    dp[value] = run(value - 2) + run (value - 1);

    return dp[value];
}

int main() {

    cout << run(8);

    return 0;
}