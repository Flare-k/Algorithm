#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <vector>
using namespace std;

/*
1. 구조체로 다시 정리
2. 기본기/FloodFill/벽뚫기.cpp에 있는 것처럼 모든 벽 케이스를 받고
벽이 임시적으로 뚫렸다는 가정하에 복수의 BFS를 돌려봤으나 시간초과로 잘못구현했다고 판단.
*/

const int MAX = 1001;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int arr[MAX][MAX];
bool visit[MAX][MAX][2];
int row, col;

struct Node {
    int y, x;
    int crash, cnt;
};

enum {
    SPACE,
    WALL
};

int BFS() {
    queue<Node> q;
    q.push({0, 0, 0, 1});  // x,y좌표 & wall 부순횟수, 현재 칸수
    visit[0][0][0] = true;

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        int y = now.y;
        int x = now.x;
        int crash = now.crash; // 벽을 부수면 +1
        int cnt = now.cnt;  // 현재 이동 중인 칸 수

        if (y == row - 1 && x == col - 1) return cnt;
        
        for (int i = 0; i < 4; i++) {
            int ny = now.y + dy[i];
            int nx = now.x + dx[i];

            if (0 <= ny && ny < row && 0 <= nx && nx < col) {
                if (arr[ny][nx] == WALL && !crash) {  // 벽이면서 아직 부순적이 없다면
                    visit[ny][nx][crash + 1] = true;
                    q.push({ny, nx, crash + 1, cnt + 1});
                } 
                else if (arr[ny][nx] == SPACE && !visit[ny][nx][crash]) {  //벽이 아니지만 아직 방문한 적이 없다면
                    visit[ny][nx][crash] = true;
                    q.push({ny, nx, crash, cnt + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> row >> col;
    
    for (int i = 0; i < row; i++) {
        string road;
        cin >> road;
        for (int j = 0; j < col; j++) {
            arr[i][j] = road[j] - '0';
        }
    }

    cout << BFS();

    return 0;
}