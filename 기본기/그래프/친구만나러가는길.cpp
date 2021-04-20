#include <iostream>
#include <cstring>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int map[3][5] = {
    0, 0, 0, 2, 1,
    1, 0, 1, 0, 0,
    3, 0, 0, 0, 1
};
// 친구: 2, 치즈: 3

bool visit[3][5];

struct Node {
    int x, y, level;
};

Node q[15];
int head, tail;

int BFS(int x, int y, int tx, int ty) {
    memset(visit, false, sizeof(visit));
    memset(q, 0, sizeof(q));

    head = 0;
    tail = 1;
    
    q[head] = {x, y};
    visit[x][y] = true;

    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 5) continue;
            if (map[nx][ny] == 1) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = true;
            q[tail++] = {nx, ny, now.level + 1};

            if (nx == tx && ny == ty) {
                return now.level + 1;
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int res1 = BFS(0, 0, x1, y1);
    int res2 = BFS(x1, y1, x2, y2);

    cout << res1 + res2;

    return 0;
}