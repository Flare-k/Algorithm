#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int x, y;
    int dir;
    int lev;
};

int arr[5][4] = {
    0, 0, 0, 0,
    0, 1, 0, 0,
    0, 0, 0, 0,
    0, 0, 1, 9,
    1, 0, 1, 0
};

int used[5][4][4];  // x, y, dir;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
enum {
    UP,
    DOWN,
    RIGHT,
    LEFT
};

queue<Node> q;

int isKill(int x, int y, int dir) {
    for (int i = 0; i < 10; i++) {
        int nx = x + (dx[dir] * i);
        int ny = y + (dy[dir] * i);

        if (nx < 0 || ny < 0 || nx >= 5 || ny >= 4) return 0;
        if (arr[nx][ny] == 1) return 0;
        if (arr[nx][ny] == 9) return 1;
    }

    return 0;
}

int push(int x, int y, int dir, int lev) {
    if (used[x][y][dir] == 1) return 0;
    if (arr[x][y] == 1) return 0;
    if (x < 0 || y < 0 || x >= 5 || y >= 4) return 0;

    used[x][y][dir] = 1;
    q.push({x, y, dir, lev});
    
    return 1;
}


int run(int x, int y) {
    q.push({x, y, UP, 0});
    used[x][y][UP] = 1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (isKill(now.x, now.y, now.dir) == 1) return now.lev;

        if (now.dir == UP || now.dir == DOWN) {
            push(now.x, now.y, LEFT, now.lev + 1);
            push(now.x, now.y, RIGHT, now.lev + 1);
        }
        else if (now.dir == RIGHT || now.dir == LEFT) {
            push(now.x, now.y, UP, now.lev + 1);
            push(now.x, now.y, DOWN, now.lev + 1);
        }

        int nx = now.x + dx[now.dir];
        int ny = now.y + dy[now.dir];

        push(nx, ny, now.dir, now.lev + 1);
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << run(4, 1);

    return 0;
}