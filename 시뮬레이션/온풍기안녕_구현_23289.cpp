#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};
const int wdx[5][3] = {{0, 0, 0}, {-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1}};
const int wdy[5][3] = {{0, 0, 0}, {1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {-1, 0, 1}};

const int MAX = 23;
int arr[MAX][MAX];      // 방
int acc[MAX][MAX];      // 방
bool visit[MAX][MAX];   // 온풍기 바람이 지나갔는지
bool check[MAX][MAX];   // 온도 조절 여부
bool wall[MAX][MAX][5];  // 벽

int R, C, K, W;

struct Node {
    int x, y, num;
};

enum {
    EMPTY, RIGHT, LEFT, UP, DOWN
};

vector<Node> research;     // 조사가 필요한 곳
vector<Node> blower; // 온풍기 위치
vector<int> way = {RIGHT, DOWN};

bool checkBoundary(int x, int y) {
    if (x >= 1 && x <= R && y >= 1 && y <= C) return true;
    return false;
}

bool checkWall(int x, int y, int nx, int ny, int d, int dir) {
    if (dir == 1) {
        if (wall[x][y][d] == false) return true;
    }
    else if (dir == 0) {
        if (d == RIGHT) {
            int ux = x - 1;
            int uy = y;
            if (!wall[x][y][UP] && !wall[ux][uy][RIGHT]) return true;
        }
        else if (d == LEFT) {
            int ux = x - 1;
            int uy = y;
            if (!wall[x][y][UP] && !wall[ux][uy][LEFT]) return true;
        }
        else if (d == DOWN) {
            int bx = x;
            int by = y - 1;
            if (!wall[x][y][LEFT] && !wall[bx][by][DOWN]) return true;
        }
        else if (d == UP) {
            int bx = x;
            int by = y - 1;
            if (!wall[x][y][LEFT] && !wall[bx][by][UP]) return true;
        }
    }
    else if (dir == 2) {
        if (d == RIGHT) {
            int ux = x + 1;
            int uy = y;
            if (!wall[x][y][DOWN] && !wall[ux][uy][RIGHT]) return true;
        }
        else if (d == LEFT) {
            int ux = x + 1;
            int uy = y;
            if (!wall[x][y][DOWN] && !wall[ux][uy][LEFT]) return true;
        }
        else if (d == DOWN) {
            int bx = x;
            int by = y + 1;
            if (!wall[x][y][RIGHT] && !wall[bx][by][DOWN]) return true;

        }
        else if (d == UP) {
            int bx = x;
            int by = y + 1;
            if (!wall[x][y][RIGHT] && !wall[bx][by][UP]) return true;
        }       
    }

    return false;
}

// 온풍기에서 바람이 나오는 경우
void run() {
    queue<Node> q;

    for (auto now : blower) {
        memset(visit, false, sizeof(visit));

        int dir = now.num;
        int x = now.x + dx[dir];
        int y = now.y + dy[dir];
        if (!checkBoundary(x, y)) continue;

        q.push({x, y, 5});

        while (!q.empty()) {
            Node now = q.front();
            q.pop();
            
            x = now.x;
            y = now.y;

            arr[x][y] += now.num;
            if (now.num == 1) continue;

            for (int k = 0; k < 3; k++) {
                int nx = x + wdx[dir][k];
                int ny = y + wdy[dir][k];

                if (checkBoundary(nx, ny)) {
                    if (!visit[nx][ny] && checkWall(x, y, nx, ny, dir, k)) {
                        visit[nx][ny] = true;
                        q.push({nx, ny, now.num - 1});
                    }
                }
            }
        }

    }
}

// 온도 조절
void controlTemp() {
    memset(check, false, sizeof(check));
    memset(acc, 0, sizeof(acc));

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {

            for (int k : way) { // RIGHT OR DOWN
                int nx = i + dx[k];
                int ny = j + dy[k];

                if (!checkBoundary(nx, ny)) continue;
                if (check[nx][ny] == true) continue;
                if (wall[i][j][k]) continue;

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
        if (arr[1][i] > 0) arr[1][i]--;
        if (arr[R][i] > 0) arr[R][i]--;
    }
    
    for (int i = 2; i < R; i++) {
        if (arr[i][1] > 0) arr[i][1]--;
        if (arr[i][C] > 0) arr[i][C]--;
    }
}

// 모든 칸이 K 이상인지 검사
bool inspectK() {
    for (auto room : research) {
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
                research.push_back({i, j, arr[i][j]});
            }
            else if (arr[i][j] >= 1 && arr[i][j] <= 4) {
                blower.push_back({i, j, arr[i][j]});
            }
            arr[i][j] = 0;
        }
    }

    cin >> W;

    for (int i = 0; i < W; i++) {
        int x, y, t;
        cin >> x >> y >> t;

        if (t == 0) {
            wall[x][y][UP] = true;
            wall[x - 1][y][DOWN] = true;
        }
        else {
            wall[x][y][RIGHT] = true;
            wall[x][y + 1][LEFT] = true;
        }
    }

    int chocolate = 0;

    while (1) {
        if (chocolate > 100) break;
        run();
        controlTemp();
        decreaseEdge();
        chocolate++;
        if (inspectK()) break;
    }

    cout << chocolate;

    return 0;
}