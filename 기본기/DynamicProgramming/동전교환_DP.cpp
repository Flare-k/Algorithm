#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Top-Down

vector<int> coins = {10, 40, 50};
int dp[1001];

int changeCoins(int changes) {

    if (changes < 0) return 999;
    if (changes == 10) return 1;
    if (changes == 40) return 1;
    if (changes == 50) return 1;

    int a = changeCoins(changes - 10);
    int b = changeCoins(changes - 40);
    int c = changeCoins(changes - 50);

    int good = a + 1;
    good = min(good, b + 1);
    good = min(good, c + 1);

    return good;
}

int main() {
    cout << changeCoins(80);
    return 0;
}
