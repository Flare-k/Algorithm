#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define MAX 51
using namespace std;

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int direction[4] = {0, 2, 4, 6};
int N, M, K;
int answer;
struct Node {
    int x, y, m, s, d;
    int cnt;    // board에서 파이어볼 개수 카운팅
    int odd; // 홀수만 카운팅
    int even;
};
struct Dir {
    int x, y;
};
Node board[MAX][MAX];
vector<Node> fireball;

void run() {
    memset(board, {}, sizeof(board));

    for (int i = 0; i < fireball.size(); i++) {
        Node now = fireball[i];

        int nx = now.x + dx[now.d] * (now.s % N);
        int ny = now.y + dy[now.d] * (now.s % N);

        while (nx < 1) nx += N;
        while (nx > N) nx -= N;
        while (ny < 1) ny += N;
        while (ny > N) ny -= N;

        board[nx][ny].x = nx;
        board[nx][ny].y = ny;
        board[nx][ny].d = now.d;
        board[nx][ny].m += now.m;
        board[nx][ny].s += now.s;
        board[nx][ny].cnt++;

        if (now.d % 2) board[nx][ny].odd++;
        else board[nx][ny].even++;
    }

    fireball.clear();

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (board[i][j].cnt == 0 || board[i][j].m == 0) continue;
            
            Node now = board[i][j];
            
            if (now.cnt == 1) {
                fireball.push_back({i, j, now.m, now.s, now.d, 0, 0, 0});
            }
            else if (now.cnt > 1) {
                int m = now.m / 5;
                int s = now.s / now.cnt;
                
                if (m == 0) continue;
                
                for (int k = 0; k < 4; k++) {
                    if (now.cnt == now.odd || now.cnt == now.even) {
                        fireball.push_back({i, j, m, s, direction[k], 0, 0, 0});
                    }
                    else {
                        fireball.push_back({i, j, m, s, direction[k] + 1, 0, 0, 0});
                    }
                }
            }
        }
    }

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    
    for (int i = 0; i < M; i++) {
        int r, c, m, s, d;
        cin >> r >> c >> m >> s >> d;
        fireball.push_back({r, c, m, s, d});
    }

    for (int i = 0; i < K; i++) {
        run();
    }
    
    int answer = 0;

    for (int i = 0; i < fireball.size(); i++) {
        answer += fireball[i].m;
    }

    cout << answer << '\n';

	return 0;
}
