#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 101;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int arr[MAX][MAX];
bool visit[MAX][MAX];
int r, c, k;

struct Node {
    int x, y;
};

vector<int> answer;

void run(int x, int y) {
    int cnt = 0;
    queue<Node> q;

    q.push({x, y});
    visit[x][y] = true;
    cnt++;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0 ; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (visit[nx][ny]) continue;
            if (arr[nx][ny] == 1) continue;

            q.push({nx, ny});
            visit[nx][ny] = true;
            cnt++;
        }
    }
    
    answer.push_back(cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c >> k;

    int x1, y1, x2, y2;

    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;

        y1 = r - y1;
        y2 = r - y2;

        for (int i = y2; i < y1; i++) {
            for (int j = x1; j < x2; j++) {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 0 && !visit[i][j]) run(i, j);
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << '\n';
    for (int num : answer) {
        cout << num << ' ';
    }

    return 0;
}