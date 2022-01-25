#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 51;
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int map[MAX][MAX];
int tmp[MAX][MAX];
bool visit[MAX][MAX];
bool enabled[MAX][MAX];
bool check[MAX];
int N, M, virusCnt, cnt, limit;
int answer = 21e8;
enum {
    EMPTY, WALL, VIRUS
};
struct Node {
    int x, y, dist;
};

vector<Node> virus;
vector<Node> active;

int run() {
    memset(visit, false, sizeof(visit));
    memset(enabled, false, sizeof(enabled));
    memcpy(tmp, map, sizeof(tmp));

    queue<Node> q;
    int d = 0;
    
    for (Node v : active) {
        q.push({v.x, v.y, 0});
        visit[v.x][v.y] = true;
        enabled[v.x][v.y] = true;
    }

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visit[nx][ny] || map[nx][ny] == WALL) continue;

            if (enabled[now.x][now.y] == true && map[nx][ny] == VIRUS && enabled[nx][ny] == false) enabled[nx][ny] = true;

            q.push({nx, ny, now.dist + 1});
            tmp[nx][ny] = now.dist + 1;
            visit[nx][ny] = true;

            if (map[nx][ny] == EMPTY) d = max(d, tmp[nx][ny]);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (tmp[i][j] == 0 && !enabled[i][j]) return - 1;
        }
    }
    
    if (d == 5) {
        d += 0;
    }
    return d;
}

void virusCheck() {
    for (int i = 0; i < virusCnt; i++) {
        if (check[i]) active.push_back({virus[i].x, virus[i].y, 0});
    }
}

void combination(int level, int start) {
    if (level == M) {
        virusCheck();
        
        int result = run();
        if (result == -1) cnt++;
        else answer = min(answer, result);
        limit++;

        active.clear();
        return;
    }

    for (int i = start; i < virusCnt; i++) {
        if (check[i]) continue;
        check[i] = true;
        combination(level + 1, i + 1);
        check[i] = false;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == VIRUS) virus.push_back({i, j});
        }
    }

    virusCnt = virus.size();

    combination(0, 0);

    if (limit == cnt) answer = -1;

    cout << answer;

    return 0;
}
