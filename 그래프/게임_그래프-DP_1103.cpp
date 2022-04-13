#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 51
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
char arr[MAX][MAX];
bool visit[MAX][MAX];
int dp[MAX][MAX];   // x, y에서 갈 수 있는 최대 가짓 수
int N, M;
int answer;

int dfs(int x, int y) {
    if ((x < 0 || x >= N || y < 0 || y >= M) || arr[x][y] == 'H') return 0;

    if (visit[x][y]) {
        cout << -1 << '\n';
        exit(0);
    }

    if (dp[x][y] != -1) return dp[x][y];

    visit[x][y] = true;
    dp[x][y] = 0;
    int jump = arr[x][y] - '0';

    for (int i = 0; i < 4; i++) {
        int nx = x + (dx[i] * jump);
        int ny = y + (dy[i] * jump);

        dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
    }

    visit[x][y] = false;
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    cout << dfs(0, 0) << '\n';;

	return 0;
}