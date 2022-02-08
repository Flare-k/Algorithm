#include <iostream>
#include <iomanip>
#define MAX 31
using namespace std;

// 동서남북
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
bool visit[MAX][MAX];
int N;
double dir[4];
double answer;

void run(int x, int y, int level, double cnt) {
    // 단순한 경로만 찾기
    if (level == N) {
        answer += cnt;  // 가능한 모든 단순한 경로의 확률 합하기
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;   // 없어도 될듯?
        if (visit[nx][ny]) continue;

        visit[x][y] = true;
        run(nx, ny, level + 1, cnt * dir[i]);   // 곱해야함
        visit[nx][ny] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < 4; i++) {
        cin >> dir[i];
        dir[i] *= 0.01;
    }

    run(15, 15, 0, 1.0);

    cout << setprecision(15);
    cout << answer;

    return 0;
}
