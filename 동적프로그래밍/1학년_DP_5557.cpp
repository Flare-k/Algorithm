#include <iostream>
#include <cstring>
using namespace std;

int n;
int target;
int arr[101];
long long dp[101][1001];

long long run(int level, int sum) {
    if (sum < 0 || sum > 20) return 0;

    if (level == n - 2) {
        if (sum == target) dp[level][sum] = 1;
        else dp[level][sum] = 0;
        
        return dp[level][sum];
    }

    if (dp[level][sum] != -1) return dp[level][sum];

    long long ret = 0;

    ret += run(level + 1, sum - arr[level + 1]);
    ret += run(level + 1, sum + arr[level + 1]);

    return dp[level][sum] = ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    
    cin >> target;

    memset(dp, -1, sizeof(dp));

    cout << run(0, arr[0]);

    return 0;
}