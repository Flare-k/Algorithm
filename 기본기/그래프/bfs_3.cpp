#include <iostream>
#include <cstring>
using namespace std;

// queue STL 안 쓰고 BFS
// 며칠만에 꽉 채울 수 있을까?

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x;
    int y;
};

Node q[20] = {{0, 2}, {2, 0}};

int map[3][3] = {0, 0, 1,
                0, 0, 0,
                1, 0, 0};

int head;
int tail;   // 배열의 맨끝
int cnt = 0;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    head = 0;
    tail = 2;   // 시작점이 두 군데인 경우.

    while (head != tail) {
        Node now = q[head];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 3) continue;
            if (map[nx][ny] != 0) continue;

            map[nx][ny] = map[now.x][now.y] + 1;
            q[tail++] = {nx, ny};

        }
        head++;
        cnt++;
    }


    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    Node last = q[tail - 1];

    cout << "최대 " << map[last.x][last.y] << "일 만에 꽉 채울 수 있다.\n";

    return 0;
}