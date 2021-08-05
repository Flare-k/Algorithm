#include <iostream>
#include <cstring>
using namespace std;

int N, M;
const int MAX = 1001;
int miro[MAX][MAX];
int acc[MAX][MAX] = {0};
int dir[MAX][MAX];

const int dx[] = {-1, -1, 0};
const int dy[] = {0, -1, -1};

enum {
    DOWN,
    RIGHT
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    
    cin >> N >> M;

    for (int i = 0; i < N + 1; i++) {
        acc[i][M] = -1;
    }

    for (int i = 0; i < M + 1; i++) {
        acc[N][i] = -1;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> miro[i][j];
        }
    }

    N--;
    M--;

    for (int i = N; i >= 0; i--) {
        for (int j = M; j >= 0; j--) {
            if (i == N && j == M) {
                acc[i][j] = miro[i][j];
                continue;
            }

            if (acc[i][j + 1] > acc[i + 1][j]) {    // right가 작을 경우
                acc[i][j] = acc[i][j + 1] + miro[i][j];
                dir[i][j] = RIGHT;
            }
            else {
                acc[i][j] = acc[i + 1][j] + miro[i][j];
                dir[i][j] = DOWN;
            }
        }
    }

    int sum = 0;
    int nx = 0, ny = 0;
    while (1) {
        //cout << nx << ", " << ny << '\n';   // 디버깅용 출력
        sum += miro[nx][ny];
        if (nx == N && ny == M) break;
        if (dir[nx][ny] == RIGHT) ny++;
        else nx++;
    }

    cout << sum;

    return 0;
}