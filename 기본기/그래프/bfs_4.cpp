#include <iostream>
#include <cstring>
using namespace std;

// queue STL 안 쓰고 BFS
// 섬의 면적

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x;
    int y;
};

Node q[20];

int map[4][5] = {
    0, 0, 1, 0, 0,
    0, 0, 1, 0, 0,
    0, 1, 1, 1, 0,
    0, 0, 1, 0, 0
};

int head;
int tail;   // 배열의 맨끝
int cnt = 0;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    q[head] = {0, 2};
    map[0][2] = 0;

    head = 0;
    tail = 1;

    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 5) continue;
            if (map[nx][ny] == 0) continue;

            q[tail++] = {nx, ny};
            map[nx][ny] = 0;
        }
        cnt++;
    }

    cout << cnt;

    return 0;
}