#include <iostream>
#include <algorithm>
#include <deque>
#define MAX 13
#define KMAX 11
using namespace std;

// →, ←, ↑, ↓
const int dx[5] = {0, 0, 0, -1, 1};
const int dy[5] = {0, 1, -1, 0, 0};
enum {
    WHITE, RED, BLUE
};
struct Node {
    int x, y, d;
};
int answer;
int N, K;
int color[MAX][MAX];    // 색칠된 칸
deque<int> board[MAX][MAX];
Node horse[KMAX];   // 각 말의 좌표
deque<int> tmp;
bool flag;

bool checkRange(int x, int y) {
    if (x < 1 || x > N || y < 1 || y > N) return false;
    return true;
}

void moveHorse() {
    for (int i = 1; i <= K; i++) {
        tmp.clear();
        Node now = horse[i];
        int x = now.x;
        int y = now.y;
        int d = now.d;

        while (board[x][y].back() != i) {
            tmp.push_front(board[x][y].back());
            board[x][y].pop_back();
        }

        tmp.push_front(board[x][y].back());
        board[x][y].pop_back();

        int nx = x + dx[d];
        int ny = y + dy[d];

        // blue
        if (!checkRange(nx, ny) || color[nx][ny] == BLUE) {
            int nd = d <= 2 ? 3 - d : 7 - d; // 방향 반대로 이동
            nx = x + dx[nd];
            ny = y + dy[nd];

            int step = 1;  // Blue|Red|Blue 인 경우 (제자리 그대로있어야함)
            if (!checkRange(nx, ny) || color[nx][ny] == BLUE) {
                nx -= dx[nd];
                ny -= dy[nd];
                step = 0;
            }

            if (color[nx][ny] == RED && step) {
                reverse(tmp.begin(), tmp.end());
            }

            for (int num : tmp) {
                if (num == i) horse[num] = {nx, ny, nd};
                else horse[num] = {nx, ny, horse[num].d};
                board[nx][ny].push_back(num);
            }
        }
        else  {
            if (color[nx][ny] == RED) reverse(tmp.begin(), tmp.end());
            for (int num : tmp) {
                horse[num] = {nx, ny, horse[num].d};
                board[nx][ny].push_back(num);
            }
        }

        if (board[nx][ny].size() >= 4) {
            flag = true;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> color[i][j];
        }
    }

    for (int i = 1; i <= K; i++) {
        int r, c, d;
        cin >> r >> c >> d;
        horse[i] = {r, c, d};
        board[r][c].push_back(i);
    }

    for (int t = 1; t <= 1000; t++) {
        moveHorse();

        if (flag) {
            cout << t << '\n';
            break;
        }
    }

    if (!flag) cout << -1 << '\n';

	return 0;
}