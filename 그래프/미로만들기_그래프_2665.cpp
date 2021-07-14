#include <iostream>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct Node {
    int x, y;
};

int n;
const int MAX = 51;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int arr[MAX][MAX];
int visit[MAX][MAX];

void run() { 
    for (int i = 0; i < MAX; i++) {    
        for (int j = 0; j < MAX; j++) {
            visit[i][j] = 987654321;
        }
    }
    queue<Node> q;
    q.push({0, 0});
    visit[0][0] = 0;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0 ; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            if (arr[nx][ny] == 1) { // Possible
                if (visit[nx][ny] > visit[now.x][now.y]) {
                    visit[nx][ny] = visit[now.x][now.y];
                    q.push({nx, ny});
                }
            }
            else {    // darkRoom
                if (visit[nx][ny] > visit[now.x][now.y] + 1) {
                    visit[nx][ny] = visit[now.x][now.y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            arr[i][j] = s[j] - '0';
        }
    }

    run();

    cout << visit[n-1][n-1];

    return 0;
}