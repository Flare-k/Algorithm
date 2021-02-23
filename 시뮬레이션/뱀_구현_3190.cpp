#include <iostream>
#include <cstring>
#include <vector>
#include <deque>

using namespace std;

// 어렵당....ㅠㅠ  turn하는 건 생각했지만 뱀의 머리와 꼬리를 Deque으로 구성해야할 생각을 하지 못했다.

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int dest = 0;
// 우 좌 하 상

int turn(int d, char c) {
    if (c == 'L') {
        if (d == 0) return 3;
        else if (d == 1) return 2;
        else if (d == 2) return 0;
        else if (d == 3) return 1;
    }
    else if (c == 'D') {
        if (d == 0) return 2;
        else if (d == 1) return 3;
        else if (d == 2) return 1;
        else if (d == 3) return 0;
    }
    return 1;
}


int main() {
    init();

    int N, K;
    cin >> N >> K;
    
    int visit[101][101];
    memset(visit, 0, sizeof(visit));

    // 사과의 좌표
    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        visit[r - 1][c - 1] = 1;
    }

    int L;
    cin >> L;

    vector<pair<int, char>> snake;
    // 뱀의 이동경로
    for (int i = 0; i < L; i++) {
        int dist;
        char dir;
        cin >> dist >> dir;
        snake.push_back({dist, dir});
    }
    // 입력 완료

    deque<pair<int, int>> dq;
    int x = 0, y = 0;
    int cnt = 0;
    int idx = 0;

    dq.push_back({x, y});
    // visit = 1 = apple , visit = 2 = snake
    visit[x][y] = 2;

    while (1) {
        cnt++;
        
        int nx = x + dx[dest];
        int ny = y + dy[dest];

        // 벽을 만나거나 뱀의 몸을 부딪히면 종료
        if (visit[nx][ny] == 2 || (nx < 0 || nx >= N || ny < 0 || ny >= N)) {
            break;
        }
        // 움직인 좌표가 빈공간이라면?  -> 머리는 나가고 꼬리는 칸을 비워줘야함
        else if (visit[nx][ny] == 0) {
            visit[nx][ny] = 2;  // 해당 칸에 뱀의 머리 표시
            visit[dq.back().first][dq.back().second] = 0;   // 꼬리 칸은 비워줌
            dq.pop_back();
            dq.push_front({nx, ny});    // 다음 머리의 좌표이므로 앞에서 넣어줘야 함
        }
        // 움직인 좌표에 사과가 있다면?
        else if (visit[nx][ny] == 1) {
            visit[nx][ny] = 2;
            dq.push_front({nx, ny});
        }

        // 뱀이 움직이는 방향을 바꾸는 때라면?
        if (idx < snake.size()) {
            if (cnt == snake[idx].first) {  // 뱀이 이동한 거리와 cnt가 같으면 회전
                if (snake[idx].second == 'L') {
                    dest = turn(dest, 'L');
                } 
                else if (snake[idx].second == 'D') {
                    dest = turn(dest, 'D');
                }
                idx++;
            }
        }

        x = nx;
        y = ny;
    }

    cout << cnt;

    return 0;
}