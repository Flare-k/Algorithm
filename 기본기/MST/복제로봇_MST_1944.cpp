#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <vector>
#define MAX 51
#define KEY_MAX 2601
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int map[MAX][MAX];
bool visit[MAX][MAX];
int vect[KEY_MAX];
int N, M;
enum {
    ROAD, WALL
};
struct Node {
    int x, y, dist;
};

vector<Node> list;

bool cmp(Node a, Node b) {
    if (a.dist < b.dist) return true;
    return false;
}

int getBoss(int ch) {
    if (vect[ch] == 0) return ch;

    int res = getBoss(vect[ch]);
    vect[ch] = res;

    return res;
}

void setGroup(int c1, int c2) {
    int g1 = getBoss(c1);
    int g2 = getBoss(c2);

    if (g1 == g2) return;
    vect[g2] = g1;
}


int run(int from, int x, int y) {
    memset(visit, false, sizeof(visit));
    queue<Node> q;
    q.push({x, y, 0});
    visit[x][y] = true;

    int ret = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if (visit[nx][ny] || map[nx][ny] == WALL) continue;

            visit[nx][ny] = true;
            q.push({nx, ny, now.dist + 1});

            if (map[nx][ny] > WALL) {
                list.push_back({from, map[nx][ny], now.dist + 1});
                ret++;
            }
            
            if (ret == M) return ret;
        }
    }

    return ret;
}

void init() {
    string route;
    int idx = 3;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> route;
        for (int j = 0; j < N; j++) {
            if (route[j] == '0') map[i][j] = ROAD;
            else if (route[j] == '1') map[i][j] = WALL;
            else if (route[j] == 'S') map[i][j] = 2;
            else if (route[j] == 'K') map[i][j] = idx++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // 초기화
    init();

    // 거리
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] > WALL) {
                int ret = run(map[i][j], i, j);

                if (ret != M) {
                    cout << -1;
                    return 0;
                }
            }
        }
    }

    int cnt = 0, answer = 0;
    int size = list.size();

    sort(list.begin(), list.end(), cmp);

    for (int i = 0; i < size; i++) {
        if (getBoss(list[i].x) != getBoss(list[i].y)) {
            cnt++;
            answer += list[i].dist;
            setGroup(list[i].x, list[i].y);

            if (cnt == M) break;
        }
    }

    cout << answer;

    return 0;
}