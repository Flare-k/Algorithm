#include <iostream>
#include <queue>
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAX = 100;
bool carrot[MAX][MAX];   // 당근을 심어야 하는지
bool visit[MAX][MAX];   // 방문한적이 있는지
int N, R, C;
struct Node {
    int x, y;
};

void run() {
    queue<Node> q;
    q.push({R, C});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        bool flag;

        if (carrot[now.x][now.y] == true) flag = false;
        else flag = true;

        for (int i = 0 ; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visit[nx][ny] == true) continue;

            q.push({nx, ny});
            carrot[nx][ny] = flag;
            visit[nx][ny] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> R >> C;

    visit[R][C] = true;
    carrot[R][C] = true;
    run();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (carrot[i][j]) cout << 'v';
            else cout << '.';
        }
        cout << '\n';
    }

    return 0;
}