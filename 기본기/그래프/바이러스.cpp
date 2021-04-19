#include <iostream>
using namespace std;

struct Node {
    int x;
    int y;
};

Node node[10000];
int map[100][100];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int head, tail, n;

void BFS(int x1, int y1, int x2, int y2) {
    node[0] = {x1, y1};
    node[1] = {x2, y2};

    map[x1][y1] = 1;
    map[x2][y2] = 1;

    head = 0;
    tail = 2;

    while (head != tail) {
        Node now = node[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (map[nx][ny] != 0) continue;

            map[nx][ny] = map[now.x][now.y] + 1;
            node[tail++] = {nx, ny};
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;
    
    cin >> n;
    cin >> a >> b >> c >> d;

    BFS(a, b, c, d);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }

    return 0;
}