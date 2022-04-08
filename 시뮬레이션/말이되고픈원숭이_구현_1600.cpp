#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define MAX 201
using namespace std;

const int hx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
const int hy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int K, R, C;
int answer;
int board[MAX][MAX];
bool visit[31][MAX][MAX];
struct Node {
    int x, y, k, dist;
};

int run() {
    if (R == 1 && C == 1) return 0;
    answer = 21e8;
    queue<Node> q;
    q.push({0, 0, 0, 0});
    visit[0][0][0] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        
        if (now.x == R - 1 && now.y == C - 1) {
            answer = min(answer, now.dist);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            int nk = now.k;
            
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (board[nx][ny] == 1 || visit[nk][nx][ny]) continue;

            q.push({nx, ny, nk, now.dist + 1});
            visit[nk][nx][ny] = true;
        }

        if (now.k < K) {
            for (int i = 0; i < 8; i++) {
                int nx = now.x + hx[i];
                int ny = now.y + hy[i];
                int nk = now.k + 1;

                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (board[nx][ny] == 1 || visit[nk][nx][ny]) continue;

                q.push({nx, ny, nk, now.dist + 1});
                visit[nk][nx][ny] = true;
            }
        }
    }

    if (answer == 21e8) answer = -1;

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K >> C >> R;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }
    
    cout << run() << '\n';;

	return 0;
}

/*
1
5 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 1 1
0 0 0 1 0
>> 6
*/