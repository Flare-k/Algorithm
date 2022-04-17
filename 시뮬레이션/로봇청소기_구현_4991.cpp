#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#define MAX 21
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int board[MAX][MAX];
int acc[MAX][MAX];
bool visit[MAX][MAX];
bool used[MAX];
int mst[MAX][MAX];
int N, M, answer;
enum { ROAD, WALL, DUST };
struct Node {
    int x, y, dist;
};
vector<Node> vec;

void bfs(int x, int y) {
    memset(visit, false, sizeof(visit));
    memset(acc, -1, sizeof(acc));

    queue<Node> q;
    q.push({x, y, 0});
    visit[x][y] = true;
    acc[x][y] = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visit[nx][ny] || board[nx][ny] == WALL) continue;

            visit[nx][ny] = true;
            q.push({nx, ny, now.dist + 1});
            acc[nx][ny] = acc[now.x][now.y] + 1;
        }
    }
}

void run(int level, int i, int sum) {
    if (level == vec.size() - 1) {
        answer = min(answer, sum);
        return;
    }

    for (int j = 1; j < vec.size(); j++) {
        if (used[j]) continue;
        used[j] = true;
        run(level + 1, j, sum + mst[i][j]);
        used[j] = false;
    }
}

void init () {
    memset(board, 0, sizeof(board));
    memset(mst, 0, sizeof(mst));
    fill(used, used + MAX, false);
    answer = 21e8;
    vec.clear();

    for (int i = 0; i < N; i++) {
        string path;
        cin >> path;

        for (int j = 0; j < M; j++) {
            if (path[j] == '.') board[i][j] = ROAD;
            else if (path[j] == 'x') board[i][j] = WALL;
            else if (path[j] == '*') {
                board[i][j] = DUST;
                vec.push_back({i, j});
            }
            else if (path[j] == 'o') {
                board[i][j] = ROAD;
                vec.insert(vec.begin(), {i, j});
            }
        }
    }

    for (int i = 0; i < vec.size(); i++) {
        int sx = vec[i].x;
        int sy = vec[i].y;

        bfs(sx, sy);    // i에서 각 쓰레기와의 거리

        for (int j = 0; j < vec.size(); j++) {
            int ex = vec[j].x;
            int ey = vec[j].y;

            mst[i][j] = acc[ex][ey];    // i와 j의 거리

            if (mst[i][j] == -1) {
                answer = -1;
                return;
            }
        }        
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (cin >> M >> N){
        if (N == 0 && M == 0) break;
        init();
        run(0, 0, 0);
        cout << answer << '\n';
    }

	return 0;
}