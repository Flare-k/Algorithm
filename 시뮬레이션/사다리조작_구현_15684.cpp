#include <iostream>
using namespace std;

const int MAX_R = 31, MAX_C = 11;
bool visit[MAX_R][MAX_C];
int level;
bool flag;
int N, M, H, a, b;

void run(int row, int cnt) {
    if (flag) return;

    if (level == cnt) {
        bool promising = true;

        for (int i = 1; i <= N; i++) {
            int c = i;

            for (int r = 0; r < H; r++) {
                if (visit[r][c]) c++;
                else if (c > 1 && visit[r][c - 1]) c--;
            }

            if (i != c) {
                promising = false;
                break;
            }
        }

        if (promising) flag = true;
        
        return;
    }

    for (int i = row; i < H; i++) {
        for (int j = 1; j < N; j++) {
            if (!visit[i][j - 1] && !visit[i][j] && !visit[i][j + 1]) {
                visit[i][j] = true;
                run(i, cnt + 1);
                visit[i][j] = false;
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // N = 세로줄, M = 처음에 연결돼 있는 가로줄
    // H = 가로에 놓을 수 있는 전체 가로줄
    cin >> N >> M >> H;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        visit[a - 1][b] = true;
    }

    for (int i = 0; i <= 3; i++) {
        level = i;

        run(0, 0);

        if (flag) {
            cout << level << '\n';
            return 0;
        }
    }

    cout << - 1 << '\n';
    return 0;
}


// 5 5 6
// a b
// 1 1  (b, b+1)을 1번째 줄에서 연결
// 3 2
// 2 3
// 5 1
// 5 4