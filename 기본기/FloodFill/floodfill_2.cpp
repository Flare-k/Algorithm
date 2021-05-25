#include <iostream>
using namespace std;
// 색 채우기 (7로 색칠의 의미 출력)

int map[3][4] = {
    0, 0, 0, 0,
    0, 1, 1, 1,
    0, 1, 0, 0
};  // 1은 벽을 의미

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int used[3][4];

struct Node {
    int x, y;
};

Node q[12];
int head, tail;

int main() {
    q[0] = {0, 1};
    head = 0;
    tail = 1;
    map[0][1] = 7;  // (0,1) 색칠
    used[0][1] = 1; // 처음 시작 지점

    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 4) continue;
            if (map[nx][ny] == 1 || used[nx][ny]) continue;

            used[nx][ny] = 1;
            map[nx][ny] = 7;
            q[tail++] = {nx, ny};
        }
        
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}