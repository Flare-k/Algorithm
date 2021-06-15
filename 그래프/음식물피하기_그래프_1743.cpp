#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 101;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int r, c, trash;
int map[MAX][MAX];
bool check[MAX][MAX];

struct Node {
    int x, y;
};

int run(int x, int y) {
    queue<Node> q;

    q.push({x, y});
    check[x][y] = true;

    int cnt = 1;    // 파라미터로 받은 (x, y) 자체가 쓰레기가 있는 곳이므로 처음 값은 1이다.

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (check[nx][ny]) continue;
            if (map[nx][ny] == 0) continue;

            check[nx][ny] = true;
            q.push({nx, ny});
            cnt++;
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> trash;

    int x, y;
    for (int i = 0; i < trash; i++) {
        cin >> x >> y;
        map[x - 1][y - 1] = 1;
    }

    int maxCnt = -1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (map[i][j] == 1 && !check[i][j]) {
                maxCnt = max(maxCnt, run(i, j));
            }
        }
    }

    cout << maxCnt;

    return 0;
}