#include <iostream>
#include <cstring>
using namespace std;

// queue STL 안 쓰고 BFS
// 두 지점에서 출발할 경우, 총 거리

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int map[3][4] = {
    0, 0, 0, 0,
    1, 0, 1, 0,
    0, 0, 0, 0
};

struct Node {
    int x, y, level;
};

Node q[20];
bool visit[3][4];
int head;
int tail;   // 배열의 맨끝

int BFS(int startX, int startY, int destX, int destY) {
    head = 0;
    tail = 1;

    memset(q, 0, sizeof(Node) * 20);
    memset(visit, false, sizeof(visit));

    q[head] = {startX, startY, 0};
    visit[startX][startY] = true;

    int ans = 0;

    while (head != tail) {
        Node now = q[head++];

        if (now.x == destX && now.y == destY) {
            ans = now.level;
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

    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // (0, 0)에서 (2, 0)을 가는 최단 거리 + (2, 0)에서 (0, 2)을 가는 최단 거리

    int res = 0;

    res = BFS(0, 0, 2, 0) + BFS(2, 0, 0, 2);

    cout << res;

    return 0;
}