#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#define MAX 51
using namespace std;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int board[MAX][MAX];
bool visit[MAX][MAX];
int R, C, answer;

struct Node {
    int x, y, dist;
};

// 선택한 땅의 거리
void run(int x, int y) {
    memset(visit, false, sizeof(visit));
    queue<Node> q;
    q.push({x, y, 0});
    visit[x][y] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        answer = max(answer, now.dist);
        
        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (visit[nx][ny] || board[nx][ny] == 0) continue;

            visit[nx][ny] = true;
            q.push({nx, ny, now.dist + 1});
        }
    }
}

// 바다로 구분된 육지들의 고유 번호 할당
void disunite(int x, int y, int num) {
    queue<Node> q;
    q.push({x, y});
    visit[x][y] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (visit[nx][ny] || board[nx][ny] == 0) continue;

            visit[nx][ny] = true;
            board[nx][ny] = num;
            q.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        string path;
        cin >> path;
        for (int j = 0; j < C; j++) {
            if (path[j] == 'L') board[i][j] = 1;
            else board[i][j] = 0;
        }
    }

    int num = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == 1 && !visit[i][j]) {
                ++num;
                disunite(i, j, num);
            }
        }
    }

    for (int k = 1; k <= num; k++) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] == k) run(i, j);
            }
        }
    }

    cout << answer << '\n';

	return 0;
}