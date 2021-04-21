#include <iostream>
#include <cstring>
using namespace std;

// 섬에서 가장 가까운 거리 구하기

int map[5][5] = {
    0, 1, 0, 0, 0,
    1, 1, 0, 0, 0,
    1, 0, 0, 0, 0,
    1, 0, 0, 0, 0,
    0, 0, 0, 0, 0,
};

bool visit[5][5];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x, y, level;
};

int tX = 4, tY = 4;

int head, tail;
Node q[30];

int BFS() {
    memset(visit, false, sizeof(visit));

    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (visit[nx][ny] || map[nx][ny] == 1) continue;

            q[tail++] = {nx, ny, now.level + 1};

            visit[nx][ny] = true;
            if (nx == tX && ny == tY) {
                return now.level + 1;
            }
        }
    }

    return 0;
}

int main() {
    head = 0;
    tail = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (map[i][j] == 1) {
                q[tail++] = {i, j, 0};
                visit[i][j] = true;
            }
        }
    }

    cout << BFS();

    return 0;
}