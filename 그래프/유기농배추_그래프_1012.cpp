#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

const int MAX = 10000 + 1;
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
int vegetable[MAX][MAX];
bool visit[MAX][MAX];
int M, N, K;  // 가로길이, 세로길이, 배추의 개수

void DFS(int x, int y) {
   visit[x][y] = true;
   for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];

      if (nx < 0 || M <= nx || ny < 0 || N <= ny) continue;
      if (vegetable[nx][ny] == 1 && !visit[nx][ny]) {
         DFS(nx, ny);
      }
   }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;  // 전체 반복횟수
    cin >> T;

    while (T--) {
        cin >> M >> N >> K;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                vegetable[i][j] = 0;
            }
        }

        for (int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            vegetable[a][b] = 1;  // 배추심기
        }

        int cnt = 0;
        
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (vegetable[i][j] == 1 && !visit[i][j]) {
                cnt++;
                DFS(i, j);
                }
            }
        }
        cout << cnt << endl;

        memset(vegetable, 0, sizeof(vegetable));
        memset(visit, false, sizeof(visit));
    }

    return 0;
}