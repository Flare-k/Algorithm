#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// DFS x DP 

int r, c;
const int MAX = 500;
vector<vector<int>> arr(MAX, vector<int>(MAX));
vector<vector<int>> dp(MAX, vector<int>(MAX));

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};


int run(int x, int y) {
    if (x == r - 1 && y == c - 1) return 1;
    if (dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
        if (arr[nx][ny] < arr[x][y]) {
            dp[x][y] = dp[x][y] + run(nx, ny);
        }
    }

    return dp[x][y];
}

void init() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
}

int main() {
    cin >> r >> c;    

    init();

    long long cnt = run(0, 0);
    cout << cnt;

    return 0;
}