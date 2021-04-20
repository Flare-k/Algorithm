#include <iostream>
#include <queue>
using namespace std;

int r, c;
int grill[1000][1000];
bool visit[1000][1000];

struct Node {
    int x, y;
};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};


void BFS(int x, int y) {
    queue<Node> q;
    q.push({x, y});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (grill[nx][ny] == 1) continue;
            if (visit[nx][ny]) continue;

            grill[nx][ny] = grill[now.x][now.y] + 1;
            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grill[i][j];
        }
    }

    int x, y;
    cin >> x >> y;

    BFS(x, y);

    int ans = -21e8;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grill[i][j] > ans) ans = grill[i][j];
        }
    }

    cout << ans;

    return 0;
}