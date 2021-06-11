#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int x, y;
};

int map[4][5] = {
    0, 0, 0, 0, 0,
    0, 1, 0, 1, 0,
    1, 1, 0, 1, 0,
    0, 0, 0, 0, 0
};
bool visited[4][5];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main() {

    queue<Node> q;

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 5) continue;
            if (map[nx][ny] == 1) continue;
            if (visited[nx][ny]) continue;

            visited[nx][ny] = true;
            map[nx][ny] = map[now.x][now.y] + 1;
            q.push({nx, ny});
        }
    }

    cout << map[3][0];

    return 0;
}