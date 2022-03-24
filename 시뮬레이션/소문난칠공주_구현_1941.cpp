#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#define MAX 5
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int board[MAX][MAX];
bool visit[MAX][MAX];
bool used[MAX * MAX];
int answer;
struct Node {
    int x, y;
};
vector<Node> v;

bool checkDasom() {
    int dasom = 0;

    for (int i = 0; i < v.size(); i++) {
        if (board[v[i].x][v[i].y] == 1) dasom++;
    }

    if (dasom >= 4) return true;
    return false;
}

bool checkAdjacent() {
    v.clear();

    for (int i = 0; i < MAX * MAX; i++) {
        if (used[i]) v.push_back({i / 5, i % 5});
    }

    queue<Node> q;
    Node first = v.front();
    q.push({first.x, first.y});
    
    memset(visit, false, sizeof(visit));
    visit[first.x][first.y] = true;
    
    int cnt = 1;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;
            if (visit[nx][ny]) continue;

            if (used[nx * 5 + ny]) {
                cnt++;
                visit[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    if (cnt == 7) return true;
    return false;
}

void run(int level, int start) {
    if (level == 7) {
        if (checkAdjacent() && checkDasom()) answer++;
        return;
    }

    for (int i = start; i < MAX * MAX; i++) {
        if (used[i]) continue;

        used[i] = true;
        run(level + 1, i + 1);
        used[i] = false;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string ch;

    for (int i = 0; i < MAX; i++) {
        cin >> ch;
        for (int j = 0; j < MAX; j++) {
            if (ch[j] == 'S') board[i][j] = 1;
        }
    }

    run(0, 0);

    cout << answer << '\n';

    return 0;
}