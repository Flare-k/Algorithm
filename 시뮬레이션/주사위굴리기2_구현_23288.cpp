#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

// 동 남 서 북
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int N, M, K;
const int MAX = 21;
int map[MAX][MAX];
int score[MAX][MAX];
bool visit[MAX][MAX];
int dice[4][3] = {
    0, 2, 0,
    4, 1, 3,
    0, 5, 0,
    0, 6, 0
};

int& bottom = dice[3][1];
int answer = 0;

enum {
    EAST, SOUTH, WEST, NORTH
};

struct Dir {
    int x, y;
};

void scoreInit(int x, int y) {
    vector<Dir> v;
    queue<Dir> q;

    v.push_back({x, y});
    q.push({x, y});
    visit[x][y] = true;
    int cnt = 1;

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (score[now.x][now.y] != score[nx][ny]) continue;
            if (visit[nx][ny] == true) continue;

            visit[nx][ny] = true;
            q.push({nx, ny});
            v.push_back({nx, ny});
            cnt++;
        }
    }

    if (cnt > 1) {
        int s = score[x][y];
        for (int i = 0; i < v.size(); i++) {
            int x = v[i].x;
            int y = v[i].y;
            score[x][y] = cnt * s;
        }
    }
}

void rollingDice(int d) {
    // East
    if (d == EAST) {
        int b = dice[3][1];
        int r = dice[1][2];
        for (int i = 2; i > 0; i--) {
            dice[1][i] = dice[1][i - 1];
        }
        dice[1][0] = b;
        dice[3][1] = r;
    }
    else if (d == SOUTH) {
        int b = dice[3][1];
        for (int i = 3; i > 0; i--) {
            dice[i][1] = dice[i - 1][1];
        }
        dice[0][1] = b;
    }
    else if (d == WEST) {
        int b = dice[3][1];
        int l = dice[1][0];
        for (int i = 0; i < 2; i++) {
            dice[1][i] = dice[1][i + 1];
        }
        dice[1][2] = b;
        dice[3][1] = l;
    }
    else if (d == NORTH) {
        int u = dice[0][1];
        for (int i = 0; i < 3; i++) {
            dice[i][1] = dice[i + 1][1];
        }
        dice[3][1] = u;
    }
}

void run() {
    int x = 0, y = 0, dir = 0;

    while (K--) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
            dir = dir % 2 == 0 ? 2 - dir : 4 - dir;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        // 점수 획득, 조건 필수.. 조건 안 달면? score 끼리 엉키게 됨
        if (!visit[nx][ny]) scoreInit(nx, ny);

        // 주사위 구르기
        rollingDice(dir);

        if (map[nx][ny] < bottom) {
            dir++;
            if (dir == 4) dir = 0;
        }
        else if (map[nx][ny] > bottom) {
            dir--;
            if (dir < 0) dir = 3;
        }

        answer += score[nx][ny];
        
        x = nx;
        y = ny;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            score[i][j] = map[i][j];
        }
    }

    run();
    cout << answer;

    return 0;
}