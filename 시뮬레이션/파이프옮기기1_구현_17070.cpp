#include <iostream>
#include <algorithm>
#include <queue>
#define MAX 17
using namespace std;

const int dx[] = {0, 1, 1};
const int dy[] = {1, 0, 1};
int N, cnt;
int arr[MAX][MAX];

enum {
    H, V, D
};
struct Node {
    int x, y, dist, dir;
};


void run() {
    queue<Node> q;
    q.push({1, 2, 0, H});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.x == N && now.y == N) {
            cnt++;
            continue;
        }
        
        for (int dir = 0; dir < 3; dir++) {
            if (dir == 1 && now.dir == H) continue;
            if (dir == 0 && now.dir == V) continue;

            int nx = now.x + dx[dir];
            int ny = now.y + dy[dir];

            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (arr[nx][ny] == 1) continue;
            
            bool flag = false;

            if (dir == D) {
                for (int r = nx - 1; r <= nx; r++) {
                    for (int c = ny - 1; c <= ny; c++) {
                        if (arr[r][c] == 1) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) break;
                }
            }

            if (!flag) q.push({nx, ny, now.dist + 1, dir});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }

    run();

    cout << cnt << '\n';

    return 0;
}