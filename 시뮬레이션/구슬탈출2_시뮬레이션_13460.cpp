#include <iostream>
#include <queue>
#include <utility>

using namespace std;


const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};
queue<pair<pair<int, int>, pair<int, int>>> marble;
bool visit[11][11][11][11] = {false};
char board[11][11];
int rx, ry, bx, by;


int BFS() {
    int cnt = 0;
    marble.push({{rx, ry}, {bx, by}});
    visit[rx][ry][bx][by] = true;

    while (!marble.empty()) {
        int size = marble.size();

        while (size--) {
            int redX = marble.front().first.first;
            int redY = marble.front().first.second;

            int blueX = marble.front().second.first;
            int blueY = marble.front().second.second;
            
            marble.pop();

            // 빨간 구슬만 구멍에 위치한다면 최소 횟수 리턴
            if (board[redX][redY] == 'O' && board[redX][redY] != board[blueX][blueY]) {
                return cnt;
            }

            for (int i = 0; i < 4; i++) {
                int n_redX = redX;
                int n_redY = redY;

                int n_blueX = blueX;
                int n_blueY = blueY;

                // 해당 방향으로 #이 나올때까지 이동하기 위해 while문 이용.. 
                while (board[n_redX + dx[i]][n_redY + dy[i]] != '#' && board[n_redX][n_redY] != 'O') {
                    n_redX += dx[i];
                    n_redY += dy[i];
                }

                while (board[n_blueX + dx[i]][n_blueY + dy[i]] != '#' && board[n_blueX][n_blueY] != 'O') {
                    n_blueX += dx[i];
                    n_blueY += dy[i];
                }

                // 빨간 구슬과 파란 구슬이 만나는 경우
                if (n_redX == n_blueX && n_redY == n_blueY) {
                    if (board[n_redX][n_blueY] == 'O') continue;
                    // 많이 이동한 경우를 한칸 뒤로 이동시킨다.
                    if (abs(n_redX - redX) + abs(n_redY - redY) < abs(n_blueX - blueX) + abs(n_blueY - blueY)) {
                        n_blueX -= dx[i];
                        n_blueY -= dy[i];
                    }
                    else {
                        n_redX -= dx[i];
                        n_redY -= dy[i];
                    }
                }

                if (visit[n_redX][n_redY][n_blueX][n_blueY]) continue;

                marble.push({{n_redX, n_redY}, {n_blueX, n_blueY}});
                visit[n_redX][n_redY][n_blueX][n_blueY] = true;
            }
            
        }
        if (cnt == 10) return -1;
        cnt++;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int r, c;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') {
                rx = i;
                ry = j;
            } 
            else if (board[i][j] == 'B'){
                bx = i;
                by = j;
            }
        }
    }

    cout << BFS();

    return 0;
}