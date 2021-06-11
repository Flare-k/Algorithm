#include <iostream>
#include <queue>
using namespace std;

int map[5][6] = {
    1, 1, 0 ,0 ,0, 0,
    1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 1,
    0, 0, 0, 1, 1, 1
};

bool visit[5][6];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x, y, level;
};

Node q[100];
int head;
int tail;

// 한 영역을 모두 q에 담기
void checkIsland() {
    head = 0;
    tail = 1;

    visit[0][0] = true;
    q[head] = {0, 0, 0};

    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 6) continue;
            if (visit[nx][ny]) continue;
            if (map[nx][ny] == 0) continue;

            visit[nx][ny]  = true;
            q[tail++] = {nx, ny, 0};
        }
    }

}

int findDistance() {
    head = 0;
    
    // 거리 찾기
    while (head != tail) {
        Node now = q[head++];

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 6) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny]  = true;
            q[tail++] = {nx, ny, now.level + 1};

            if (map[nx][ny] == 1) return now.level + 1;
        }
    }

    return -1;
}

int main() {

    checkIsland();
    cout << findDistance();

   return 0;
}