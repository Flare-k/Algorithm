#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define MAX 101
using namespace std;

int N, K, L;
// 우 하 좌 상
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int map[MAX][MAX]; // 사과? 뱀?

enum {
    EMPTY, APPLE, SNAKE
};

struct Node {
    int dist;
    char dir;
};

struct Dir {
    int x, y;
};

vector<Node> path;

void run() {
    deque<Dir> snake;

    int x = 1, y = 1, cnt = 0, dir = 0;
    int start = 0, end = path.size();

    snake.push_back({x, y});
    map[x][y] = SNAKE;  // 출발점

    // 싸이클 한 번에 한 칸
    while (1) {
        cnt++;

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if ((nx < 1 || nx > N || ny < 1 || ny > N) || map[nx][ny] == SNAKE) break;

        
        // 만약 빈칸이라면
        if (map[nx][ny] == EMPTY) {
            map[nx][ny] = SNAKE;
            map[snake.back().x][snake.back().y] = EMPTY;   // 꼬리 지우기
            snake.pop_back();
            snake.push_front({nx, ny});
        }
        // 만약 사과가 있다면
        else if (map[nx][ny] == APPLE) {
            map[nx][ny] = SNAKE;
            snake.push_front({nx, ny});
        }
        
        // 방향 전환을 해야한다면
        if ((start < end) && cnt == path[start].dist) {
            // 이동하고자 하는 칸만큼 이동했다면
            if (path[start].dir == 'D') dir = dir < 3 ? dir + 1 : 0;
            else if (path[start].dir == 'L') dir = dir > 0 ? dir - 1 : 3;
            
            start++;
        }

        x = nx;
        y = ny;
    }

    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    int x, y;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        map[x][y] = APPLE;
    }

    cin >> L;

    int dist;
    char dir;
    for (int i = 0; i < L; i++) {
        cin >> dist >> dir;
        path.push_back({dist, dir});
    }

    run();

    return 0;
}