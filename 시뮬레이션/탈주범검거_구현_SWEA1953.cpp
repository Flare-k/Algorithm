#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 50
using namespace std;

int N, M, T, R, C, L;
int board[MAX][MAX][4];
bool visit[MAX][MAX];
struct Node {
    int x, y;
};
// {북, 동, 남, 서}
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
int dir[8][4] = {
    {0, 0, 0, 0},
    {1, 1, 1, 1},
    {1, 0, 1, 0},
    {0, 1, 0, 1},
    {1, 1, 0, 0},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
    {1, 0, 0, 1}
};

void run(int idx) {
    memset(visit, false, sizeof(visit));
    queue<Node> q;
    q.push({R, C});
    visit[R][C] = true;
    int cnt = 1;
    L--;

    while (L--) {
        int size = q.size();

        while (size--) {
            Node now = q.front();
            q.pop();

            int x = now.x;
            int y = now.y;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if (visit[nx][ny]) continue;

                if (board[x][y][i] && board[nx][ny][(i + 2) % 4]) {
                    visit[nx][ny] = true;
                    cnt++;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << '#' << idx << ' ' << cnt << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;

    for (int test = 1; test <= T; test++) {
        cin >> N >> M >> R >> C >> L;

        memset(board, 0, sizeof(board));
        memset(visit, false, sizeof(visit));

        int num;
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j++) {
                cin >> num;
                for (int k = 0; k < 4; k++) {
                    board[i][j][k] = dir[num][k];
                }
            }
        }

        run(test);
    }

	return 0;
}
