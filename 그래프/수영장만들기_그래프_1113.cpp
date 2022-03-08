#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#define MAX 52
using namespace std;

int N, M, answer, maxx;
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int arr[MAX][MAX];
struct Node {
    int x, y;
};
queue<Node> q;

void run(int num) {
    arr[0][0] = num;
    q.push({0, 0});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx > N + 1 || ny < 0 || ny > M + 1) continue;

            if (arr[nx][ny] < num) {
                arr[nx][ny] = num;
                q.push({nx, ny});
            }
        }
    }
}

void checkPool(int num) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] < num) {
                answer++;
                arr[i][j] += 1;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    string line;

    for (int i = 1; i <= N; i++) {
        cin >> line;
        for (int j = 1; j <= M; j++) {
            arr[i][j] = line[j - 1] - '0';
            if (maxx < arr[i][j]) maxx = arr[i][j];
        }
    }

    for (int num = 1; num <= maxx; num++) {
        run(num);
        checkPool(num);
    }

    cout << answer << '\n';

    return 0;
}