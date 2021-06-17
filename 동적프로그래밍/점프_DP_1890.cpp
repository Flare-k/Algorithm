#include <iostream>
#define ll long long
using namespace std;

// 1520 내리막길과 같은 알고리즘 -> DFS x DP

const int MAX = 101;
int n;
ll arr[MAX][MAX];
ll dp[MAX][MAX];

ll run(int x, int y) {
    if (x == n - 1 && y == n - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    dp[x][y] += run(x + arr[x][y], y);  // 아래로 이동
    dp[x][y] += run(x, y + arr[x][y]);  // 오른쪽으로 이동

    return dp[x][y];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }

    cout << run(0, 0);

    return 0;
}