#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const int MAX = 21;
int N;
int map[MAX][MAX];
bool visit[MAX][MAX];

struct Dir {
    int x, y, dist;
};
struct Node {
    int x, y, size, eat;
};

Node shark;
vector<Dir> fish;

bool cmp(Dir& a, Dir& b) {
    if (a.dist < b.dist) return true;
    else if (a.dist == b.dist) {
        if (a.x < b.x) return true;
        else if (a.x == b.x) return a.y < b.y;
    }
    return false;
}

int run() {
    memset(visit, false, sizeof(visit));
    queue<Dir> q;
    fish.clear();

    q.push({shark.x, shark.y, 0});
    visit[shark.x][shark.y] = true;

    while (!q.empty()) {
        Dir now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 1 || nx > N || ny < 1 || ny > N) continue;
            if (visit[nx][ny]) continue;
            if (map[nx][ny] > shark.size) continue;

            q.push({nx, ny, now.dist + 1});
            visit[nx][ny] = true;
            if (map[nx][ny] != 0 && map[nx][ny] < shark.size) fish.push_back({nx, ny, now.dist + 1});
        }
    }

    int dist = 0;

    if (!fish.empty()) {
        sort(fish.begin(), fish.end(), cmp);
        Dir f = fish.front();
        dist = f.dist;
        map[shark.x][shark.y] = 0;
        map[f.x][f.y] = 9;

        if (shark.eat + 1 == shark.size) shark = {f.x, f.y, shark.size + 1, 0};
        else shark = {f.x, f.y, shark.size, shark.eat + 1};
    }

    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) shark = {i, j, 2, 0};
        }
    }

    int answer = 0;

    while (1) {
        int dist = run();
        if (dist != 0) answer += dist;
        else break;
    }

    cout << answer;

    return 0;
}