#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <bitset>
#include <set>
#include <tuple>
#include <queue>
#define MAX 52
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
int board[MAX][MAX];
bool visit[MAX][MAX];
int list[MAX * MAX];
int row, col;
int room, maxx, total;
using edge = tuple<int, int, int, int>;
set<edge> st;

struct Node {
    int x, y;
};

void run(int x, int y, int num) {
    int cnt = 1;
    board[x][y] = num;
    visit[x][y] = true;
    queue<Node> q;
    q.push({x, y});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;
            if (visit[nx][ny]) continue;
            if (st.find({now.x, now.y, nx, ny}) != st.end()) continue;

            board[nx][ny] = num;
            visit[nx][ny] = true;
            q.push({nx, ny});
            cnt++;
        }
    }

    list[num] = cnt;
    maxx = max(maxx, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> col >> row;

    int n;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> n;

            bitset<4> b(n);
            string idx = b.to_string();

            for (int k = 0; k < 4; k++) {
                if (idx[k] == '1') {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

                    st.insert({i, j, nx, ny});
                    st.insert({nx, ny, i, j});
                }
            }
        }
    }

    int num = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!visit[i][j]) {
                num++;
                run(i, j, num);
            }
        }
    }
  
    room = num;

    memset(visit, false, sizeof(visit));
    
    for (int k = 1; k <= room; k++) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == k) {
                    for (int d = 0; d < 4; d++) {
                        int nx = i + dx[d];
                        int ny = j + dy[d];

                        if (nx < 0 || nx >= row || ny < 0 || ny >= col) continue;

                        if (board[nx][ny] != k) {
                            total = max(total, list[k] + list[board[nx][ny]]);
                        }
                    }
                }
            }
        }
    }
    
    cout << room << '\n' << maxx << '\n' << total << '\n';

	return 0;
}