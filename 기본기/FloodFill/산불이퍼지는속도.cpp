#include <iostream>
#include <queue>
using namespace std;

int mountain[3][4] = {
    0, 0, 0, 0,
    1, -1, 0, 1,
    0, 0, 1, -1
};
bool visit[3][4];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x, y;
    int level;
};

queue<Node> q;

void init() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (mountain[i][j] == 1) {
                q.push({i, j, 1});
                visit[i][j] = true;
            }
        }
    }
}

int main() {

    init();

    int finalDay = -21e8;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 4) continue;
            if (mountain[nx][ny] == -1 || visit[nx][ny]) continue;

            visit[nx][ny] = true;
            q.push({nx, ny, now.level + 1});
            if (finalDay < now.level + 1) finalDay = now.level + 1;
        }
    }

    cout << finalDay;

    return 0;
}