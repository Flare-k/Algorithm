#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1001;
const int INF = 987654321;

int N, res;
int team[MAX];
int dp[MAX];

int run(int idx) {
    if (idx == N) return 0;

    int &res = dp[idx];
    if (res != -1) return res;

    res = 0;
    int low = INF;
    int high = -1;
    for (int i = idx; i < N; i++) {
        low = min(low, team[i]);
        high = max(high, team[i]);

        res = max(res, (high - low) + run(i + 1));
    }
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> team[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << run(0) << '\n';

    return 0;
}