#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#define MAX 101
using namespace std;

int N, M, answer;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
bool visit[MAX][MAX];
bool check[MAX][MAX];
struct Node {
    int x, y;
};
vector<Node> arr[MAX][MAX];

bool cmp(Node& A, Node& B) {
    if (A.x < B.x) return true;
    else if (A.x == B.x) return A.y < B.y;
    return false;
}

void run() {

    while (1) {
        memset(visit, false, sizeof(visit));
        queue<Node> q;
        q.push({1, 1});
        check[1][1] = true;
        visit[1][1] = true;
        bool flag = false;

        while (!q.empty()) {
            Node now = q.front();
            q.pop();
            
            int size = arr[now.x][now.y].size();

            if (size > 0) {
                for (Node next : arr[now.x][now.y]) {
                    check[next.x][next.y] = true;
                    flag = true;
                }

                arr[now.x][now.y].clear();
            }

            for (int d = 0; d < 4; d++) {
                int nx = now.x + dx[d];
                int ny = now.y + dy[d];

                if (nx < 1 || nx > N || ny < 1 || ny > N) continue;

                if (!visit[nx][ny] && check[nx][ny]) {
                    q.push({nx, ny});
                    visit[nx][ny] = true;
                }
            }
        }

        if (!flag) break;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (check[i][j]) answer++;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;

        arr[x][y].push_back({a, b});
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j].size() > 0) sort(arr[i][j].begin(), arr[i][j].end(), cmp);
        }
    }

    run();

    cout << answer << '\n';

    return 0;
}