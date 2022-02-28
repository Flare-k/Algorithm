#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define MAX 1001
using namespace std;

int N, M, hx, hy, ex, ey;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int arr[MAX][MAX];
bool visit[MAX][MAX][2];
int answer = 21e8;
enum {
    EMPTY, WALL
};
struct Node {
    int x, y, dist, crash;
};

void run() {
    queue<Node> q;
    q.push({hx, hy, 0, 0});
    visit[hx][hy][0] = true;    // 벽이 아닌 경우 true

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.x == ex && now.y == ey) {
            answer = min(answer, now.dist);
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > M) continue;
            
            // 벽이고 아직 한번도 부순적이 없다면
            if (arr[nx][ny] == WALL && now.crash == 0) {
                visit[nx][ny][now.crash + 1] = true;
                q.push({nx, ny, now.dist + 1, now.crash + 1});
            }
            // 도로인데 아직 지나간적이 없다면
            else if (arr[nx][ny] == EMPTY && !visit[nx][ny][now.crash]) {
                visit[nx][ny][now.crash] = true;
                q.push({nx, ny, now.dist + 1, now.crash});
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    cin >> hx >> hy;
    cin >> ex >> ey;
   
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }

    run();

    if (answer != 21e8) cout << answer << '\n';
    else cout << -1 << '\n';

    return 0;
}