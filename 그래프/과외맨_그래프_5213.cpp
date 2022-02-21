#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MAX 501
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int N;
int map[MAX][MAX * 2];
int number[MAX][MAX * 2];
bool visit[MAX][MAX * 2];
int path[MAX * MAX];
int maxx;
struct Node {
    int x, y;
};

void run() {
    queue<Node> q;
    q.push({0, 0});
    q.push({0, 1});
    visit[0][0] = true;
    visit[0][1] = true;
    path[number[0][0]] = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        maxx = max(maxx, number[now.x][now.y]);

        bool flag = false;

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N * 2) continue;
            if (map[nx][ny] == -1) continue;
            if (visit[nx][ny] == true) continue;

            // 같은 도미노 내인 경우
            if (number[now.x][now.y] == number[nx][ny]) {
                q.push({nx, ny});
                visit[nx][ny] = true;
            }
            // 다른 도미노지만 같은 수를 갖는 경우
            else if (map[now.x][now.y] == map[nx][ny]) {
                q.push({nx, ny});
                visit[nx][ny] = true;

                if (nx % 2 == 0) {
                    if (ny % 2 == 0) {
                        visit[nx][ny + 1] = true;
                        q.push({nx, ny + 1});
                    }
                    else {
                        visit[nx][ny - 1] = true;
                        q.push({nx, ny - 1});
                    }
                }
                else {
                    if (ny % 2 == 0) {
                        visit[nx][ny - 1] = true;
                        q.push({nx, ny - 1});
                    }
                    else {
                        visit[nx][ny + 1] = true;
                        q.push({nx, ny + 1});
                    }
                }

                if (path[number[nx][ny]] == 0) {
                    path[number[nx][ny]] = number[now.x][now.y];
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    memset(map, -1, sizeof(map));

    int num = 1;

    for (int i = 0; i < N; i++) {
        int a, b;

        if (i % 2 == 0) {
            for (int j = 0; j < N * 2; j += 2) {
                cin >> a >> b;
                map[i][j] = a;
                map[i][j + 1] = b;
                number[i][j] = num;
                number[i][j + 1] = num;
                num++;
            }
        }
        else {
            for (int j = 1; j < N * 2 - 1; j += 2) {
                cin >> a >> b;
                map[i][j] = a;
                map[i][j + 1] = b;
                number[i][j] = num;
                number[i][j + 1] = num;
                num++;
            }
        }
    }

    run();

    vector<int> answer;
    for (int i = maxx; i != 0; i = path[i]) {
        answer.push_back(i);
    }

    cout << answer.size() << '\n';

    for (int i = answer.size() - 1; i >= 0; i--) {
        cout << answer[i] << ' ';
    }

    return 0;
} 