#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

// 1은 벽, 2는 타겟

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int h = 6;
const int w = 7;

int arr[h][w] = {
    1, 1, 1, 1, 1, 1, 1,
    1, 2, 0, 0, 0, 0, 1,
    0, 0, 1, 1, 0, 0, 1,
    1, 0, 2, 1, 0, 0, 1,
    1, 2, 0, 0, 2, 0, 1,
    1, 1, 1, 1, 1, 1, 1
};
bool visit[h][w];

struct Node {
    int y, x;
    int lev;
};

vector<Node> things;    // 물건 리스트
int tl; // 물건 갯수

int schedule[50][5];    // 모든 경우에 대한 케이스를 다 저장한다.
int sc_used[5];
int sc_path[5];
int sl;

void init() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (arr[i][j] == 2) things.push_back({i, j});
        }
    }

    tl = things.size();
}

void run(int level) {

    if (level == tl) {
        memcpy(schedule[sl], sc_path, 5 * 4);
        sl++;
        return;
    }

    for (int i = 0; i < tl; i++) {
        if (sc_used[i]) continue;

        sc_used[i] = 1;
        sc_path[level] = i;
        run(level + 1);
        sc_path[level] = 0;
        sc_used[i] = 0;
    }
}

int bfs(int y, int x, int ty, int tx) {
    queue<Node> q;
    memset(visit, false, sizeof(visit));

    q.push({y, x});
    visit[y][x] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (visit[ny][nx]) continue;
            if (arr[ny][nx] == 1) continue;

            visit[ny][nx] = true;
            q.push({ny, nx, now.lev + 1});

            if (ny == ty && nx == tx) {
                return now.lev + 1;
            }
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // 물건의 위치에서 시작지점까지의 거리를 모두 더하면 안 되려나..

    /* 백트래킹으로 물건의 위치 조합 만들고 각 케이스마다 bfs 돌리기*/
    // 1. 물건의 위치정보 넣기
    init();

    // 2. 물건 순서 만들기 0 ~ tl
    run(0);

    // 3. 스케쥴대로 최단경로 구하기
    int y = 2;
    int x = 0;
    int min = 21e8;

    for (int i = 0; i < sl ; i++) {
        int sum = 0;
        for (int j = 0; j < tl; j++) {
            int ny = things[schedule[i][j]].y;
            int nx = things[schedule[i][j]].x;

            sum += bfs(y, x, ny, nx);   // bfs 네번 (물건이 네개이므로..)
            y = ny;
            x = nx;
        }

        sum += bfs(y, x, 2, 0); // 출발지점으로 돌아오는 bfs 한번... 총 다섯번

        if (sum < min) min = sum;
        // 다음 케이스를 위해 y, x를 다시 출발지점으로 복귀
        y = 2;
        x = 0;
    }

    cout << min;

    return 0;
}