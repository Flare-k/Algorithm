#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

int N;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int arr[MAX][MAX];
bool visit[MAX][MAX];
struct Node {
    int x, y;
};

int run(bool flag) {
    int answer = 0;
    int tmp[MAX][MAX];
    memcpy(tmp, arr, sizeof(tmp));
    memset(visit, false, sizeof(visit));

    if (flag) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (arr[i][j] == 2) arr[i][j] = 1;
            }
        }
    }

    queue<Node> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visit[i][j]) {
                q.push({i, j});
                visit[i][j] = true;

                while (!q.empty()) {
                    Node now = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int nx = now.x + dx[k];
                        int ny = now.y + dy[k];

                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                        if (arr[now.x][now.y] != arr[nx][ny]) continue;
                        if (visit[nx][ny]) continue;

                        visit[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
                
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string color;
        cin >> color;
        for (int j = 0; j < N; j++) {
            if (color[j] == 'R') arr[i][j] = 1;
            else if (color[j] == 'G') arr[i][j] = 2;
            else arr[i][j] = 3;
        }
    }

    cout << run(false) << ' ' << run(true) << '\n';

	return 0;
}