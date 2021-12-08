#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

const int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int sx[] = {-1, 0, 1, 0};
const int sy[] = {0, -1, 0, 1};
const int MAX = 4;
int arr[MAX][MAX];
bool smell[MAX][MAX];
int smellCnt[MAX][MAX];
int M, S;

struct Fish {
    int x, y, dir;
};

struct Dir {
    int px, py, x, y, val;
    string path;
};

Fish shark;
queue<Fish> fish;

void sharkMove() {
    int x = shark.x;
    int y = shark.y;
    queue<Dir> q;
    q.push({x, y, x, y, 0, ""});

    string target = "444";
    int cnt = -21e8;
    int nx, ny;

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx = now.x + sx[i];
            ny = now.y + sy[i];

            if (now.px == nx && now.py == ny) continue; // 바로 직전 좌표와 같은 경우
            if (nx < 0 || ny < 0 || nx >= MAX || ny >= MAX) continue;

            if (now.path.length() == 3) {
                if (cnt <= now.val) {
                    if (cnt == now.val) {
                        if (target > now.path) target = now.path;
                    }
                    else if (cnt < now.val) target = now.path;
                    
                    cnt = now.val;
                }
                continue;
            }

            q.push({now.x, now.y, nx, ny, now.val + arr[nx][ny], now.path + to_string(i + 1)});
        }
    }

    if (cnt > 0){
        for (char ch : target) {
            int i = (ch - '0') - 1;
            nx = x + sx[i];
            ny = y + sy[i];

            if (arr[nx][ny] > 0) {
                arr[nx][ny] = 0;
                smell[nx][ny] = true;
                smellCnt[nx][ny] = 2;
            }
            x = nx;
            y = ny;
        }

        shark = {nx, ny};

        int size = fish.size();
        while (size--) {
            Fish now = fish.front();
            fish.pop();
            if (arr[now.x][now.y] == 0) continue;
            fish.push(now);
        }
    }
}

void removeSmell() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (smellCnt[i][j] > 0) {
                smellCnt[i][j]--;
                if (smellCnt[i][j] == 0) smell[i][j] = false;
            }
        }
    }
}

bool canNotMove(int x, int y) {
    if (smell[x][y] == true) return true;
    if (shark.x == x && shark.y == y) return true;
    if (x < 0 || y < 0 || x >= MAX || y >= MAX) return true;
    return false;
}

void run() {
    while (S--) {
        queue<Fish> nq;
        int size = fish.size();

        while (size--) {
            Fish now = fish.front();
            fish.pop();

            int x = now.x;
            int y = now.y;
            int dir = now.dir;
            int odir = now.dir;

            int nx = x + dx[dir];
            int ny = y + dy[dir];
            bool flag = false;

            while (canNotMove(nx, ny)) {
                dir--;
                if (dir < 0) dir = 7;
                if (dir == odir) {
                    nx = x;
                    ny = y;
                    flag = true;
                    break;
                }
                nx = x + dx[dir];
                ny = y + dy[dir];
            }

            if (!flag) {
                arr[x][y]--;
                arr[nx][ny]++;
            }

            fish.push({nx, ny, dir});
            nq.push(now);
        }

        if (S == 0) {
            int a = 1;
        }

        removeSmell();
        sharkMove();

        // 복제 마법 완료
        while (!nq.empty()) {
            Fish now = nq.front();
            fish.push(now);
            arr[now.x][now.y]++;
            nq.pop();
        }

    }

    cout << fish.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> M >> S;

    int x, y, dir;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> dir;
        fish.push({x - 1, y - 1, dir - 1});
        arr[x - 1][y - 1]++;
    }   

    cin >> x >> y;

    shark = {x - 1, y - 1};
    run();

    return 0;
}