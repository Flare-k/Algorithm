#include <iostream>
#include <queue>
#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int r, c;
const int MAX = 101;
int map[MAX][MAX];
int d[MAX][MAX];

struct Node {
    int x, y;
};

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void run() {
    queue<Node> q;
    q.push({0, 0});
    d[0][0] = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
            if (map[nx][ny] == 1) {
                if (d[nx][ny] > d[now.x][now.y] + 1) {
                    d[nx][ny] = d[now.x][now.y] + 1;
                    q.push({nx, ny});
                }
            }
            else {
                if (d[nx][ny] > d[now.x][now.y]) {
                    d[nx][ny] = d[now.x][now.y];
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;

    for (int i = 0; i < c; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < r; j++) {
            map[i][j] = line[j] - '0';
            d[i][j] = INF;
        }
    }

    run();

    cout << d[c - 1][r - 1];

    return 0;
}