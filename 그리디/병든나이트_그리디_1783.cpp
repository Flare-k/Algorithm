#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define endl "\n"
using namespace std;

int N, M, x, y;

int step[4][4] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}};

/*
    1. 2칸 위로, 1칸 오른쪽
    2. 1칸 위로, 2칸 오른쪽
    3. 1칸 아래로, 2칸 오른쪽
    4. 2칸 아래로, 1칸 오른쪽
*/

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin >> N >> M;
   bool visit[N][M];

   x = N - 1;
   y = 0;
   visit[N - 1][0] = true;
   int cnt = 0;
   for (int num = 0; num < N * M; num++) {
      for (int i = 0; i < 4; i++) {
         int nx = x + step[i][0];
         int ny = y + step[i][1];

         if (nx >= 1 && nx < N && ny >= 1 && ny < M) {
            visit[nx][ny] = true;
            x = nx;
            y = ny;
            cnt++;
         }
      }
   }
   for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
         cout << visit[i][j] << " ";
      }
      cout << endl;
   }
   cout << cnt << endl;
   return 0;
}