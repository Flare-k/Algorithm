#include <iostream>
#include <queue>
using namespace std;

int island[5][8];
bool visit[5][8];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x, y;
};


int BFS(int x, int y) {
    queue<Node> q;
    q.push({x, y});
    visit[x][y] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 8) continue;
            if (visit[nx][ny] || island[nx][ny] == 0) continue;

            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return 1;
}

int main() {

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> island[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            if (!visit[i][j] && island[i][j] == 1) {
                cnt += BFS(i, j);
            }
        }
    }

    cout << cnt;

    return 0;
}