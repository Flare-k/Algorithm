#include <iostream>
#include <queue>
using namespace std;

int arr[4][3] = {0};
bool visit[4][3] = {false};

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

struct Node {
    int x, y;
    int level;
};

queue<Node> q;

int main() {

    // 초기값 설정
    q.push({2, 1, 1});
    arr[2][1] = 1;
    visit[2][1] = true;

    // flood fill
    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 4 || ny >= 3) continue;
            if (visit[nx][ny]) continue;

            visit[nx][ny] = true;
            arr[nx][ny] = arr[now.x][now.y] + 1;
            q.push({nx, ny, now.level + 1});
        }
    }

    // 결과 출력
    for (int i = 0 ; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}