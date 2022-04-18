#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 101
using namespace std;

const int dx[] = {0, 0, 0, 1, -1};
const int dy[] = {0, 1, -1, 0, 0};
int board[MAX][MAX];
bool visit[MAX][MAX][5];
int N, M;
int ex, ey, ed, answer;

enum { ROAD, WALL };
struct Node {
    int x, y, dir, cnt;
};

void run(int x, int y, int dir) {
    queue<Node> q;
    q.push({x, y, dir, 0});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (visit[now.x][now.y][now.dir]) continue;

        if (now.x == ex && now.y == ey && now.dir == ed) {
            answer = now.cnt;
            break;
        }

        visit[now.x][now.y][now.dir] = true;

        for (int i = 1; i <= 2; i++) {
            int ndir = !(now.dir / 3) * 2 + i;
            if (!visit[now.x][now.y][ndir]) {
                q.push({now.x, now.y, ndir, now.cnt + 1});
            }
        }

        for (int i = 1; i <= 3; i++) {
            int nx = now.x + dx[now.dir] * i;
            int ny = now.y + dy[now.dir] * i;

            if (board[nx][ny] == WALL) break;
            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            if (visit[nx][ny][now.dir]) continue;

            q.push({nx, ny, now.dir, now.cnt + 1});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
        }
    }

    int x, y, dir;
    cin >> x >> y >> dir;
    cin >> ex >> ey >> ed;

    run(x, y, dir);
   
    cout << answer << '\n';

	return 0;
}

/*
10 10
0 1 1 1 0 0 0 0 0 1
0 0 0 0 0 1 1 1 1 1
0 0 0 0 0 1 1 1 1 1
0 1 0 0 1 1 1 1 1 1
0 0 0 1 0 0 0 1 1 1
0 1 1 1 0 0 0 0 0 1
0 0 0 1 1 0 0 0 1 1
0 1 0 1 1 1 1 0 1 1
0 0 0 1 1 1 1 1 1 1
1 1 1 1 1 1 1 0 1 1
1 9 1
9 1 3
> 12

9 12
0 0 0 0 0 0 0 0 0 0 0 1
0 1 1 1 1 0 0 1 1 1 1 0
0 0 0 0 0 0 0 1 1 1 1 0
0 1 1 1 1 0 0 1 1 1 1 0
0 0 0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 0 0 1 1 1 1 0
0 1 1 1 1 0 0 0 0 0 0 0
0 1 1 1 1 0 0 1 1 1 1 0
1 0 0 0 0 0 0 0 0 0 0 0
1 1 3
9 12 3
> 10

4 2
0 0
0 0
1 0
0 0
1 1 3
4 1 3
> 7
*/