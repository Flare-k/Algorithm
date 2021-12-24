#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};
const int MAX = 22;
int arr[MAX][MAX];      // 방
int acc[MAX][MAX];      // 방
bool visit[MAX][MAX];   // 온풍기 바람이 지나갔는지
bool check[MAX][MAX];   // 온도 조절 여부
bool wall[MAX][MAX][MAX][MAX];  // 벽
int R, C, K, W;

struct Node {
    int x, y, num;
};

enum {
    EMPTY, RIGHT, LEFT, UP, DOWN
};

vector<Node> v;     // 조사가 필요한 곳
vector<Node> blower; // 온풍기 위치

bool checkBoundary(int x, int y) {
    if (x >= 1 && x <= R && y >= 1 && y <= C) return true;
    return false;
}

Node turnRight() {
    int tmp[MAX][MAX];
    memset(tmp, 0, sizeof(tmp));
    Node node;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            tmp[j][C - i + 1] = arr[i][j];
            if (arr[i][j] == 100) node = {j, C - i + 1, 0};
        }
    }

    memcpy(arr, tmp, sizeof(arr));
    return node;
}

Node turnLeft() {
    int tmp[MAX][MAX];
    memset(tmp, 0, sizeof(tmp));
    Node node;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            tmp[R - j + 1][i] = arr[i][j];
            if (arr[i][j] == 100) node = {R - j + 1, i, 0};
        }
    }

    memcpy(arr, tmp, sizeof(arr));
    return node;
}

// 온풍기에서 바람이 나오는 경우
void run() {
    queue<Node> q;

    for (auto now : blower) {
        memset(visit, false, sizeof(visit));

        int x = now.x;
        int y = now.y;
        int dir = now.num;
        Node node = {x, y, 0};
        arr[x][y] = 100;

        if (dir == UP) {
            node = turnRight();
            swap(R, C);
        }
        else if (dir == DOWN) {
            node = turnLeft();
            swap(R, C);
        }
        else if (dir == LEFT) {
            turnRight();
            node = turnRight();
        }

        x = node.x;
        y = node.y;
        arr[x][y] = 0;

        int r = x + dx[RIGHT];
        int c = y + dy[RIGHT];
        if (r < 1 || c < 1 || r > R || c > C) continue;

        arr[r][c] += 5;
        q.push({r, c, 5});

        while (!q.empty()) {
            Node now = q.front();
            q.pop();
            int x = now.x, y = now.y;
            if (now.num == 0) continue;
            visit[x][y] = true;

            // 대각 위
            int nx = x + dx[UP];
            int ny = y + dy[UP];
            int _nx = nx + dx[RIGHT];
            int _ny = ny + dy[RIGHT];

            if (checkBoundary(nx, ny), checkBoundary(_nx, _ny)) {
                if (!wall[x][y][nx][ny] && !wall[nx][ny][_nx][_ny]) {
                    if (!visit[_nx][_ny]) {
                        arr[_nx][_ny] += (now.num - 1);
                        q.push({_nx, _ny, now.num - 1});
                        visit[_nx][_ny] = true;
                    }
                }
            }
            
            // 오른쪽
            nx = x + dx[RIGHT];
            ny = y + dy[RIGHT];
            
            if (checkBoundary(nx, ny)) {
                if (!wall[x][y][nx][ny] && !visit[nx][ny]) {
                    arr[nx][ny] += (now.num - 1);
                    q.push({nx, ny, now.num - 1});
                    visit[nx][ny] = true;
                }
            }

            // 대각 아래
            nx = x + dx[DOWN];
            ny = y + dy[DOWN];
            _nx = nx + dx[RIGHT];
            _ny = ny + dy[RIGHT];

            if (checkBoundary(nx, ny), checkBoundary(_nx, _ny)) {
                if (!wall[x][y][nx][ny] && !wall[nx][ny][_nx][_ny]) {
                    if (!visit[_nx][_ny]) {
                        arr[_nx][_ny] += (now.num - 1);
                        q.push({_nx, _ny, now.num - 1});
                        visit[_nx][_ny] = true;
                    }
                }
            }
        }

        if (dir == UP) {
            turnLeft();
            swap(R, C);
        }
        else if (dir == DOWN) {
            turnRight();
            swap(R, C);
        }
        else if (dir == LEFT) {
            turnLeft();
            turnLeft();
        }
    }
}

// 온도 조절
void controlTemp() {
    memset(check, false, sizeof(check));
    memset(acc, 0, sizeof(acc));

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (arr[i][j] == 0) continue;

            for (int k = 1; k <= 4; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (nx < 1 || ny < 1 || nx > R || ny > C) continue;
                if (check[nx][ny] == true) continue;
                if (wall[i][j][nx][ny]) continue;

                int value = abs(arr[i][j] - arr[nx][ny]) / 4;

                if (arr[i][j] > arr[nx][ny]) {
                    acc[i][j] -= value;
                    acc[nx][ny] += value;
                }
                else if (arr[i][j] < arr[nx][ny]) {
                    acc[i][j] += value;
                    acc[nx][ny] -= value;
                }
            }
            check[i][j] = true;
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            arr[i][j] += acc[i][j];
        }
    }
}

// 바깥쪽 1씩 감소
void decreaseEdge() {
    for (int i = 1; i <= C; i++) {
        if (arr[0][i] > 0) arr[0][i]--;
    }
    for (int i = 1; i <= C; i++) {
        if (arr[R][i] > 0) arr[R][i]--;
    }
    for (int i = 2; i <= R - 1; i++) {
        if (arr[i][0] > 0) arr[i][0]--;
    }
    for (int i = 2; i <= R - 1; i++) {
        if (arr[i][C] > 0) arr[i][C]--;
    }
}

// 모든 칸이 K 이상인지 검사
bool inspectK() {
    for (auto room : v) {
        int x = room.x;
        int y = room.y;
        if (arr[x][y] < K) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> R >> C >> K;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 5) {
                v.push_back({i, j, arr[i][j]});
                arr[i][j] = 0;
            }
            else if (arr[i][j] >= 1 && arr[i][j] <= 4) {
                blower.push_back({i, j, arr[i][j]});
                arr[i][j] = 0;
            }
        }
    }

    cin >> W;

    for (int i = 0; i < W; i++) {
        int x, y, t;
        cin >> x >> y >> t;
        if (t == 0) {
            wall[x][y][x - 1][y] = true;
            wall[x - 1][y][x][y] = true;
        }
        else {
            wall[x][y][x][y + 1] = true;
            wall[x][y + 1][x][y] = true;
        }
    }

    int chocolate = 0;

    while (1) {
        //run();
        controlTemp();
        decreaseEdge();
        chocolate++;
        if (inspectK()) break;
    }

    cout << chocolate;

    return 0;
}
