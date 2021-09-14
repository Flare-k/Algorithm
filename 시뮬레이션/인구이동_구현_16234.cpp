#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 51;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int N, L, R;
int sum, cnt, days;

int arr[MAX][MAX];
bool visit[MAX][MAX];

struct Node {
    int x, y;
};

vector<Node> v;

void run(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        int num = abs(arr[x][y] - arr[nx][ny]);

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (L <= num && num <= R && !visit[nx][ny]) {
            visit[nx][ny] = true;
            v.push_back({nx, ny});
            sum += arr[nx][ny];
            cnt++;
            run(nx, ny);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> L >> R;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    while (1) {
        memset(visit, false, sizeof(visit));
        bool flag = false;
     
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visit[i][j]) continue;

                visit[i][j] = true;
                sum = arr[i][j];
                cnt = 1;

                v.clear();
                v.push_back({i, j});
                run(i, j);

                if (cnt >= 2) {
                    for (auto idx : v) {
                        arr[idx.x][idx.y] = sum / cnt;
                    }

                    flag = true;
                }
            }
        }

        if (flag) days++;
        else break;
    }

    cout << days;

    return 0;
}