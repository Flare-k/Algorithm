#include <iostream>
#include <cstring>
using namespace std;

// Dynamic programming으로 풀이하기
const int MAX = 31;
int n, k;
int dp[MAX][MAX];

int comb(int n, int k) {
    if (n == k || k == 0) return 1;

    int result = dp[n][k];

    if (result != -1) return result;

    result = comb(n - 1, k - 1) + comb(n - 1, k);
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;

    memset(dp, -1, sizeof(dp));
    cout << comb(n - 1, k - 1);
    
    return 0;
}