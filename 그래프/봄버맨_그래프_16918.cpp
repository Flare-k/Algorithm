#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

/* 시간초과 때문에 애먹었다ㅠㅠㅠ */

const int MAX = 201;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};
char bomb[MAX][MAX];
char cpy[MAX][MAX];

struct Node {
    int x, y;
};

vector<Node> node;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int R, C, N;
    cin >> R >> C >> N;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> bomb[i][j];
        }
    }

    int timer = 1; // 처음 1초는 아무것도 하지 않는다.

    while (timer < N) {
        // 설치되지 않은 칸에 폭탄 설치
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (bomb[i][j] == 'O') node.push_back({i, j});
                else bomb[i][j] = 'O';
            }
        }

        timer++;;
        if (timer >= N) break;

        // 기존에 설치한 폭탄 폭발
        for (int i = 0; i < node.size(); i++) {
                int x = node[i].x;
                int y = node[i].y;

                bomb[x][y] = '.';

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;

                    bomb[nx][ny] = '.';
                }
        }

        timer++;
        node.clear();

    }  // while 문

    // 출력
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << bomb[i][j];
        }
        cout << '\n';
    }

    return 0;
}