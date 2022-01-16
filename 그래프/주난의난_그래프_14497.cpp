#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int N, M;
int jx, jy, tx, ty;
const int MAX = 350;
vector<vector<char>> map(MAX, vector<char>(MAX));
vector<vector<char>> tmp(MAX, vector<char>(MAX));
bool visit[MAX][MAX];
struct Node {
    int x, y;
};

bool run() {
    memset(visit, false, sizeof(visit));
    queue<Node> q;
    q.push({jx, jy});
    visit[jx][jy] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (visit[nx][ny]) continue;
            
            visit[nx][ny] = true;

            if (nx == tx && ny == ty) return true;
            if (map[nx][ny] == '1') {
                tmp[nx][ny] = '0';
                continue;
            }
            
            q.push({nx, ny});
        }
    }

    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    cin >> jx >> jy >> tx >> ty;

    jx--; jy--;
    tx--; ty--;
    
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = s[j];
        }
    }

    int cnt = 0;
    
    while (1) {
        cnt++;
        tmp = map;
        if (run()) break;
        map = tmp;
    }

    cout << cnt;

    return 0;
}