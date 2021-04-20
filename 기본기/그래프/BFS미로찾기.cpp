#include <iostream>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int miro[4][4] = {
    0, 0, 0, 0,
    1, 1, 0, 1,
    0, 0, 0, 0,
    1, 0, 1, 0
};

struct Node {
    int x, y, level;
};

Node q[30];
bool visit[4][4];
int head, tail;

void BFS(int x, int y, int tx, int ty) {
    head = 0;
    tail = 1;

    q[head] = {x, y, 0};
    visit[x][y] = true;

    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
            if (miro[nx][ny] == 1) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = true;
            q[tail++] = {nx, ny, now.level + 1};

            if (nx == tx && ny == ty) {
                cout << now.level + 1 << "회";
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, x1, y1;
    cin >> x >> y >> x1 >> y1;

    BFS(x, y, x1, y1);

    return 0;
}