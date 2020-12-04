#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#define endl "\n"

using namespace std;

const int MAX = 1000 + 1;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int arr[MAX][MAX];
bool visit[MAX][MAX][2];
int row, col;
queue<pair<int, int>> q;

int BFS() {
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({{0, 0}, {0, 1}});  // x,y좌표 & wall 부순횟수, 현재 칸수
    visit[0][0][0] = true;

    while (!q.empty()) {
        int x = q.front().first.first;    // x좌표
        int y = q.front().first.second;   // y좌표
        int crash = q.front().second.first; // 벽을 부수면 +1
        int cnt = q.front().second.second;  // 현재 이동 중인 칸 수
        q.pop();

        if (x == row - 1 && y == col - 1) {
            return cnt;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < row && 0 <= ny && ny < col) {
                if (arr[nx][ny] && !crash) {  // 벽이면서 아직 부순적이 없다면
                    visit[nx][ny][crash + 1] = true;
                    q.push({{nx, ny}, {crash + 1, cnt + 1}});
                } 
                else if (!arr[nx][ny] && !visit[nx][ny][crash]) {  //벽이 아니지만 아직 방문한 적이 없다면
                    visit[nx][ny][crash] = true;
                    q.push({{nx, ny}, {crash, cnt + 1}});
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