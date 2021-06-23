#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
    int x, y;
    int cnt;
};

enum {
    _, W, G
};

int arr[5][5] = {
    _, _, _, _, G,
    _, _, _, W, G,
    _, G, G, _, _,
    _, G, G, W, _,
    W, _, W, _, G
};

int used[5][5];

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

queue<Node> q;


void run() {

    int maxx = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5|| ny >= 5) continue;
            if (arr[nx][ny] == W) continue;
            if (used[nx][ny]) continue;

            used[nx][ny] = 1;
            q.push({nx, ny, now.cnt + 1});
            maxx = max(maxx, now.cnt + 1);
        }
    }

    cout << maxx << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (arr[i][j] == G) {
                q.push({i, j, 0});
                used[i][j] = 1;
            }
        }
    }

    run();

    return 0;
}