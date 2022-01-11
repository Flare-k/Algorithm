#include <iostream>
using namespace std;

const int MAX = 41;
int N, M;
int dp[MAX];
int vip[MAX];

void runDP() {
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int answer() {
    int res = 1;

    for (int i = 1; i <= M; i++) {
        res *= dp[vip[i] - vip[i - 1] - 1];
    }

    return res *= dp[N - vip[M]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int num;
    for (int i = 1; i <= M; i++) {
        cin >> vip[i];
    }

    runDP();
    
    cout << answer();
    
    return 0;
}