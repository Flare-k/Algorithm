#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 501;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int r, c;

int paper[MAX][MAX];
bool visit[MAX][MAX];

struct Node {
    int x, y;
};

queue<Node> q;

int run(int x, int y) {
    int size = 1;
    
    q.push({x, y});
    visit[x][y] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if (visit[nx][ny] == true) continue;
            if (paper[nx][ny] == 0) continue;

            size++;
            visit[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return size;
}

void init() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> paper[i][j];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;

    init();

    int cnt = 0;
    int maxSize = 0;    // 그림이 하나도 없으면 0

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (paper[i][j] == 1 && !visit[i][j]) {
                cnt++;
                maxSize = max(maxSize, run(i, j));
            }
        }
    }

    cout << cnt << '\n';
    cout << maxSize << '\n';

    return 0;
}