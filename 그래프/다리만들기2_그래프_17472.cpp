#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 다리 연결하기 x 최소 스패닝 트리(MST)

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
const int MAX = 101;
int r, c;
int island[MAX][MAX];
bool visit[MAX][MAX];
int vect[MAX];

struct Node {
    int x, y, dist;
};

vector<Node> v;

bool cmp(Node a, Node b) {
    if (a.dist < b.dist) return true;
    return false;
}

int getBoss(int n) {
    if (vect[n] == 0) return n;

    int res = getBoss(vect[n]);
    vect[n] = res;
    return res;
}

void setGroup(int n1, int n2) {
    int g1 = getBoss(n1);
    int g2 = getBoss(n2);

    if (g1 == g2) return;
    vect[g2] = g1;
}

void changeIslandName(int x, int y, int r, int c, int num, int island[][MAX], bool visit[][MAX]) {
    visit[x][y] = true;
    island[x][y] = num;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (0 <= nx && nx < r && 0 <= ny && ny < c) {
            if (island[nx][ny] && !visit[nx][ny]) {
                changeIslandName(nx, ny, r, c, num, island, visit);
            }
        }
    }
}

void connectBridge(int cur) {
    queue<Node> q;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (island[i][j] == cur) {   // 특정 경우의 섬에 대한 위치만 담음
                visit[i][j] = true;
                q.push({i, j, 0});
            }
        }
    }

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        bool flag = false;

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int dist = now.dist;

            while (0 <= nx && nx < r && 0 <= ny && ny < c && island[nx][ny] != cur) {
                if (island[nx][ny] != 0) {
                    flag = true;
                    break;
                }
                nx += dx[i];
                ny += dy[i];
                dist++;
            }

            if (flag && island[nx][ny] != 0) {
                int next = island[nx][ny];
                if (dist > 1) v.push_back({cur, next, dist});
            }
        }
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;

    for (int i =0 ; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> island[i][j];
        }
    }

    int num = 0;

    for (int i = 0 ; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (island[i][j] && !visit[i][j]) {
                changeIslandName(i, j, r, c, ++num, island, visit);
            }
        }
    }

    memset(visit, false, sizeof(visit));

    for (int i = 1; i <= num; i++) {
        connectBridge(i);
    }

    sort(v.begin(), v.end(), cmp);

    int answer = 0;
    int cnt = 0;
    bool flag = false;

    for (int i = 0; i < v.size(); i++) {
        if (getBoss(v[i].x) != getBoss(v[i].y)) {
            cnt++;
            answer += v[i].dist;
            setGroup(v[i].x, v[i].y);

            if (cnt == num - 1) {
                flag = true;
                break;
            }
        }
    }

    if (flag) cout << answer << '\n';
    else cout << -1 << '\n';

    return 0;
}