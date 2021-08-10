#include <iostream>
#include <queue>
#include <cstring>
#define INF 999

using namespace std;

// BFS로 푸는 방법

int n;
const int MAX = 125;
int map[MAX][MAX];
int acc[MAX][MAX];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int run() {
    queue<Node> q;
    q.push({0, 0});
    acc[0][0] = map[0][0];

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        int minn = 21e8;
        int mx, my;

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if (acc[nx][ny] > acc[now.x][now.y] + map[nx][ny]) {
                acc[nx][ny] = acc[now.x][now.y] + map[nx][ny];
                q.push({nx, ny});
            }
        }
    }

    return acc[n - 1][n - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int problem = 1;
    while (cin >> n && n != 0) {
        memset(map, 0, sizeof(map));
        memset(check, false, sizeof(check));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                acc[i][j] = INF;
            }
        }

        cout << "Problem " << problem++ << ": " << run() << '\n';
    }

    return 0;
}
