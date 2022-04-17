// 4991 로봇청소기
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <string>
#define MAX 21
using namespace std;

int rx, ry;
int MST[MAX][MAX];
int board[MAX][MAX];
bool visit[MAX][MAX];
bool used[MAX];
int mst[MAX][MAX];
int answer;
int N, M;
bool flag;
enum { ROAD, WALL, DUST };
struct Node {
    int x, y, dist;
};
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
vector<Node> dust;
vector<vector<int>> list;

int bfs(int sx, int sy, int ex, int ey) {
    memset(visit, false, sizeof(visit));
    queue<Node> q;
    q.push({sx, sy, 0});
    visit[sx][sy] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.x == ex && now.y == ey) return now.dist;

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visit[nx][ny] || board[nx][ny] == WALL) continue;

            visit[nx][ny] = true;
            q.push({nx, ny, now.dist + 1});
        }
    }

    return -1;
}
vector<int> result;
void combination() {
    int len = dust.size();
    vector<int> v(len);

    for (int i = 0; i < len; i++) {
        v[i] = i;
    }

    int minus_cnt = 0, cnt = 0;

    do {
        int num, sum = 0;
        bool check = false;

        for (int i = 0; i < len; i++) {
            if (i == 0) num = bfs(rx, ry, dust[v[i]].x, dust[v[i]].y);
            else num = bfs(dust[v[i - 1]].x, dust[v[i - 1]].y, dust[v[i]].x, dust[v[i]].y);

            if (num == -1) {
                minus_cnt++;
                check = true;
                break;
            }
            else sum += num;
        }

        cnt++;

        if (!check) answer = min(answer, sum);

    } while (next_permutation(v.begin(), v.end()));

    if (minus_cnt == cnt) flag = true;
}

void init () {
    dust.clear();
    string path;

    for (int i = 0; i < N; i++) {
        cin >> path;

        for (int j = 0; j < M; j++) {
            if (path[j] == '.') board[i][j] = ROAD;
            else if (path[j] == 'x') board[i][j] = WALL;
            else if (path[j] == '*') {
                board[i][j] = DUST;
                dust.push_back({i, j});
            }
            else if (path[j] == 'o') {
                board[i][j] = ROAD;
                rx = i;
                ry = j;
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
        
        memset(board, 0, sizeof(board));
        memset(visit, 0, sizeof(visit));
        answer = 21e8;
        flag = false;

        init();
        combination();

        if (flag) answer = -1;
        
        result.push_back(answer);
    }


    for (int num : result) {
        cout << num << '\n';
    }

	return 0;
}

/*
7 5
.......
.o...*.
.......
.*...*.
.......
15 13
.......x.......
...o...x....*..
.......x.......
.......x.......
.......x.......
...............
xxxxx.....xxxxx
...............
.......x.......
.......x.......
.......x.......
..*....x....*..
.......x.......
10 10
..........
..o.......
..........
..........
..........
.....xxxxx
.....x....
.....x.*..
.....x....
.....x....
0 0

> 8 49 -1
*/