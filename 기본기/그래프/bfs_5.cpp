#include <iostream>
#include <cstring>
using namespace std;

// queue STL 안 쓰고 BFS
// 최단거리

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int map[3][4] = {
    0, 0, 1, 0,
    1, 0, 1, 0,
    0, 0, 0, 0
};

struct Node {
    int x;
    int y;
    int level; 
};

Node q[20] = {{0, 0, 0}};
bool visit[3][4] = { 1 };   // 맨앞에만 1 체크

int head;
int tail;   // 배열의 맨끝

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    head = 0;
    tail = 1;

    while (head != tail) {
        Node now = q[head++];

        if (now.x == 0 && now.y == 3) {
            cout << "도착, level = " << now.level << '\n';
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 3 || ny >= 4) continue;
            if (map[nx][ny] == 1) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = true;
            q[tail++] = {nx, ny, now.level + 1};
        }
    }

    return 0;
}