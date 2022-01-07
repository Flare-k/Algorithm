#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 501;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int answer;
int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];

struct Node {
    int px, py, x, y;
    int sum, cnt;
};

// ㅡ ㄴ ㄹ ㅁ
void run1() {
    queue<Node> q;
    q.push({0, 0, 0, 0, map[0][0], 1});
    visit[0][0] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.cnt == 4) {
            answer = max(answer, now.sum);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx == now.px && ny == now.py) continue;
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            
            if (!visit[nx][ny]) {
                q.push({nx, ny, nx, ny, map[nx][ny], 1});
                visit[nx][ny] = true;
            }

            q.push({now.x, now.y, nx, ny, now.sum + map[nx][ny], now.cnt + 1});
        }
    }
}

// ㅏ ㅓ ㅗ ㅜ
void run2() {
    int sum = 0;
    // ㅜ
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M - 2; j++) {
            sum = 0;
            for (int k = j; k < j + 3; k++) {
                sum += map[i][k];
            }
            sum += map[i + 1][j + 1];
            answer = max(answer, sum);
        }
    }

    // ㅗ
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < M - 2; j++) {
            sum = 0;
            for (int k = j; k < j + 3; k++) {
                sum += map[i][k];
            }
            sum += map[i - 1][j + 1];
            answer = max(answer, sum);
        }
    }
    // ㅓ
    for (int i = 1; i < M; i++) {
        for (int j = 0; j < N - 2; j++) {
            sum = 0;
            for (int k = j; k < j + 3; k++) {
                sum += map[k][i];
            }
            sum += map[j + 1][i - 1];
            answer = max(answer, sum);
        }
    }

    // ㅏ
    for (int i = 0; i < M - 1; i++) {
        for (int j = 0; j < N - 2; j++) {
            sum = 0;
            for (int k = j; k < j + 3; k++) {
                sum += map[k][i];
            }
            sum += map[j + 1][i + 1];
            answer = max(answer, sum);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    run1();
    run2();

    cout << answer;

    return 0;
}