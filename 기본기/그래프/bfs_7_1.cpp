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

void BFS(int x, int y) {
    visit[x][y] = true;
    q[0] = {x, y, 0};

    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (visit[nx][ny] || map[nx][ny] == 0) continue;

            q[tail++] = {nx, ny, 0};
            visit[nx][ny] = true;
        }
    }
}

void near() {
    head = 0;
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
                cout << now.level + 1;
                return;
            }
        }
    }
}

int main() {
    head = 0;
    tail = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (map[i][j] == 1) {
                BFS(i, j);
                near();
            }
        }
    }


    return 0;
}