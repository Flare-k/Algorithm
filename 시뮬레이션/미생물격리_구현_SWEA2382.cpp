#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX 100
using namespace std;

struct Node {
    int x, y, cnt, dir;
};
const int dx[] = {0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, -1, 1};
int T, N, M, K;
Node board[MAX][MAX];
bool visit[MAX][MAX];
int acc[MAX][MAX];
vector<Node> group;

bool checkLine(int x, int y) {
    if (x == 0 || x == N - 1) return true;
    if (y == 0 || y == N - 1) return true;
    return false;
}

void run() {
    memset(visit, false, sizeof(visit));
    memset(board, {}, sizeof(board));
    memset(acc, 0, sizeof(acc));

    for (int i = 0; i < group.size(); i++) {
        Node now = group[i];
        int d = now.dir;
        int nx = now.x + dx[d];
        int ny = now.y + dy[d];

        board[nx][ny].x = nx;
        board[nx][ny].y = ny;
        visit[nx][ny] = true;

        if (checkLine(nx, ny)) {
            board[nx][ny].cnt += (now.cnt / 2);
            board[nx][ny].dir = now.dir <= 2 ? 3 - now.dir : 7 - now.dir;
            acc[nx][ny] = max(acc[nx][ny], now.cnt);
        }
        else {
            board[nx][ny].cnt += now.cnt;
            if (acc[nx][ny] < now.cnt) {
                acc[nx][ny] = now.cnt;
                board[nx][ny].dir = now.dir;
            }
        }
    }

    group.clear();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visit[i][j] && board[i][j].cnt > 0) {
                group.push_back(board[i][j]);
            }
        }
    }
}

int result() {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += board[i][j].cnt;
        }
    }

    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;

    for (int test = 1; test <= T; test++) {
        cin >> N >> M >> K;
        
        group.clear();
        
        for (int i = 0; i < K; i++) {
            int r, c, cnt, dir;
            cin >> r >> c >> cnt >> dir;
            group.push_back({r, c, cnt, dir});
        }

        for (int i = 0; i < M; i++) {
            run();
        }

        cout << '#' << test << ' ' << result() << '\n';
    }

	return 0;
}