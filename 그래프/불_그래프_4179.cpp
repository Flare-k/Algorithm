#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>
#define MAX 1001
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int R, C;
int arr[MAX][MAX];
bool visit[MAX][MAX];
enum {
    ROAD, WALL, FIRE
};
struct Node {
    int x, y;
    int status;
    int dist;
};
deque<Node> q;

void run() {
    while (!q.empty()) {
        Node now = q.front();
        int status = now.status;
        q.pop_front();

        if (now.status == ROAD && arr[now.x][now.y] == FIRE) continue;

        if (arr[now.x][now.y] == ROAD && (now.x == 0 || now.x == R - 1 || now.y == 0 || now.y == C - 1)) {
            cout << now.dist << '\n';
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;;
            if (arr[nx][ny] == WALL || arr[nx][ny] == FIRE) continue;

            if (status == ROAD) {
                if (visit[nx][ny]) continue;
                q.push_back({nx, ny, ROAD, now.dist + 1});
            }
            else if (status == FIRE) {
                arr[nx][ny] = FIRE;
                q.push_back({nx, ny, FIRE});
            }

            visit[nx][ny] = true;
        }
    }

    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    char ch;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> ch;

            if (ch == '.') arr[i][j] = ROAD;
            else if (ch == '#') arr[i][j] = WALL;
            else if (ch == 'F') {
                arr[i][j] = FIRE;
                q.push_back({i, j, FIRE});
                visit[i][j] = true;
            }
            else if (ch == 'J') {
                arr[i][j] = ROAD;
                q.push_front({i, j, ROAD, 1});
                visit[i][j] = true;
            }
        }
    }

    run();

    return 0;
}
