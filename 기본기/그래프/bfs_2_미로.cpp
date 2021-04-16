#include <iostream>
#include <cstring>
using namespace std;

// queue STL 안 쓰고 BFS
// 시작지점 (0, 0) , 도착지점 (0, 3)

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x;
    int y;
};

Node q[30];
int map[4][4] = {0, 0, 1, 0,
                1, 0, 1, 0,
                0, 0, 0, 0,
                0, 1, 0, 1};
bool used[4][4];
int head;
int tail;   // 배열의 맨끝


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(used, false, sizeof(used));

    head = 0;
    tail = 1;

    q[head] = {0, 0};
    map[0][0] = 0;

    while (head != tail) {
        Node now = q[head];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 4) continue;
            if (map[nx][ny] == 1) continue; // 벽을 만날 경우

            if (!used[nx][ny]) {
                used[nx][ny] = true;
                map[nx][ny] = map[now.x][now.y] + 1;
                q[tail++] = {nx, ny};
            }
        }
        head++;
    }

    if (map[0][3]) {
        cout << map[0][3] << "번 만에 도착!" << '\n';
        cout << "O" << '\n';
    }
    else {
        cout << "도착 실패!" << '\n';
    }

    return 0;
}