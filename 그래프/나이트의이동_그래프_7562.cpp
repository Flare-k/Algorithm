#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

const int MAX = 301;
const int dx[8] = {2, 2, 1, 1, -2, -2, -1, -1};
const int dy[8] = {-1, 1, -2, 2, -1, 1, -2, 2};
// 나이트가 움직이는 이동경로
bool visit[MAX][MAX];

void BFS(vector<vector<int>> chess, int x, int y, int desX, int desY, int size) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = true; // 현재 있는 칸

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == desX && y == desY) {
            cout << chess[x][y] << '\n';
            // 만약 현재 x, y와 desX, desY가 같다면 q에 있는 값들 제거하고 반복문 종료
            while(!q.empty()) {
                q.pop();
            }
            break;
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < size && 0 <= ny && ny < size) {
                if (!visit[nx][ny]) {
                    visit[nx][ny] = true;
                    q.push({nx, ny});
                    chess[nx][ny] = chess[x][y] + 1;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int r;
    cin >> r;

    while(r--) {
        int size;
        cin >> size;
        vector<vector<int>> chess(size, vector<int>(size));

        int sRow, sCol, eRow, eCol;
        cin >> sRow >> sCol;  // 나이트가 현재 있는 칸. start Row & start Column
        cin >> eRow >> eCol;  // 나이트가 이동하려는 칸. end Row & end Column

        BFS(chess, sRow, sCol, eRow, eCol, size);
        memset(visit, false, sizeof(visit));
    }

    return 0;
}