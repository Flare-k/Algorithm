#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 21;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
int arr[MAX][MAX];
int mask[MAX][MAX];
bool visit[MAX][MAX];
int N;
int idx = 0;
priority_queue<int> pq; // 1~5구역 중 인구차가 가장 많이나는 경우 push

void run(int x, int y, int d1e, int d2e) {
    memset(mask, 0, sizeof(mask));
    memset(visit, 0, sizeof(visit));
    x--;
    y--;

    for (int d1 = 0; d1 <= d1e; d1++) {
        for (int d2 = 0; d2 <= d2e; d2++) {
            if (x + d1 < 0 || x + d1 >= N || y - d1 < 0 || y - d1 >= N) return;
            if (x + d2 < 0 || x + d2 >= N || y + d2 < 0 || y + d2 >= N) return;
            if (x + d1 + d2 < 0 || x + d1 + d2 >= N || y - d1 + d2 < 0 || y - d1 + d2 >= N) return;
            if (x + d2 + d1 < 0 || x + d2 + d1 >= N || y + d2 - d1 < 0 || y + d2 - d1 >= N) return;
            
            mask[x + d1][y - d1] = 5;
            mask[x + d2][y + d2] = 5;
            mask[x + d1 + d2][y - d1 + d2] = 5;
            mask[x + d2 + d1][y + d2 - d1] = 5;
        }
    }

    // 안쪽 5채우기
    for (int i = x; i < x + d1e + d2e; i++) {
        for (int j = y - d1e; j < y + d2e; j++) {
            
            if (i < 0 || i >= N || j < 0 || j >= N) continue;
            
            int cnt = 0;
            if (!visit[i][j] && mask[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if (mask[nx][ny] == 5) cnt++;
                }
            }

            if (cnt >= 3) {
                mask[i][j] = 5;
                visit[i][j] = true;
            }
        }
    }

    // 1 ~ 4 채우기
    for (int i = 0; i < x + d1e; i++) {
        for (int j = 0; j <= y; j++) {
            if (mask[i][j] == 0) mask[i][j] = 1;
        }
    }
    for (int i = 0; i <= x + d2e; i++) {
        for (int j = y; j < N; j++) {
            if (mask[i][j] == 0) mask[i][j] = 2;
        }
    }
    for (int i = x + d1e; i < N; i++) {
        for (int j = 0; j < y - d1e + d2e; j++) {
            if (mask[i][j] == 0) mask[i][j] = 3;
        }
    }
    for (int i = x + d2e + 1; i < N; i++) {
        for (int j = y - d1e + d2e; j < N; j++) {
            if (mask[i][j] == 0) mask[i][j] = 4;
        }
    }
    
    /* 디버깅용 출력 */
    // cout << ++idx << "번째 출력 \n";
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < N; j++) {
    //         cout << mask[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << "=================\n";


    int size[6];
    memset(size, 0, sizeof(size));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            size[mask[i][j]] += arr[i][j];
        }
    }

    int minn = 21e8;
    int maxx = -21e8;

    for (int i = 1; i <= 5; i++) {
        minn = min(minn, size[i]);
        maxx = max(maxx, size[i]);
    }

    pq.push(-(maxx - minn));

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int x = i;
            int y = j;

            for (int a = 1; a <= N; a++) {
                for (int b = 1; b <= N; b++) {
                    run(x, y, a, b);
                }
            }
        }
    }

    cout << -pq.top();

    return 0;
}