#include <iostream>
#include <cstring>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int map[4][6];
bool visit[4][6];

struct Node {
    int x, y;
};

int head, tail, eat = 0;

void BFS() {
    Node q[30];
    memset(visit, false, sizeof(visit));

    head = 0;
    tail = 1;

    q[head] = {0, 0};
    visit[0][0] = true;

    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 6) continue;
            if (map[nx][ny] == 1) continue;
            if (visit[nx][ny]) continue;

            if (map[nx][ny] == 2) eat++;
            q[tail++] = {nx, ny};
            visit[nx][ny] = true;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> map[i][j];
        }   
    }

    BFS();

    cout << eat;

    return 0;
}