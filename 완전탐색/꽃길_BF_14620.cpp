#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 11;
const int dx[] = {0, -1, 1, 0, 0};
const int dy[] = {0, 0, 0, 1, -1};
int N;
int map[MAX][MAX];
bool visit[MAX][MAX];
int answer = 1e9;

void checkVisit(int x, int y, bool flag) {
    for (int j = 0; j <= 4; j++) {
        int nx = x + dx[j];
        int ny = y + dy[j];
        visit[nx][ny] = flag;
    }
}

void run(int level) {
    if (level == 3) {
        int sum = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visit[i][j]) sum += map[i][j];
            }
        }
 
        answer = min(answer, sum);
        return;
    }

    for (int x = 1; x < N - 1; x++) {
        for (int y = 1; y < N - 1; y++) {
            if (!visit[x][y]) {
                bool flag = false;
                for (int i = 1; i <= 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx < 0 | nx >= N || ny < 0 || ny >= N || visit[nx][ny] == true) {
                        flag = false;
                        break;
                    }

                    flag = true;
                }

                if (flag) {
                    checkVisit(x, y, flag);
                    run(level + 1);
                    checkVisit(x, y, !flag);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    run(0);

    cout << answer;

    return 0;
}