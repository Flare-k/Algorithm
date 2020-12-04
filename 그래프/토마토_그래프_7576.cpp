#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1000 + 1;
int arr[MAX][MAX];
int a, b;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
struct tomato {
   int y, x;
};

queue<tomato> q;

void BFS() {
   while (!q.empty()) {
      int y = q.front().y;
      int x = q.front().x;
      q.pop();

      for (int i = 0; i < 4; i++) {
         int nx = x + dx[i];
         int ny = y + dy[i];

         if (0 <= nx && nx < a && 0 <= ny && ny < b) {
            if (arr[ny][nx] == 0) {
               arr[ny][nx] = arr[y][x] + 1;
               q.push({ny, nx});
            }
         }
      }
   }
}

int main() {
   cin >> a >> b;
   for (int i = 0; i < b; i++) {     //세로
      for (int j = 0; j < a; j++) {  //가로
         cin >> arr[i][j];
         if (arr[i][j] == 1) q.push({i, j});
      }
   }
   BFS();
   int result = 0;
   for (int i = 0; i < b; i++) {
      for (int j = 0; j < a; j++) {
         if (arr[i][j] == 0) {
            cout << "-1\n";
            return 0;
         }
         if (result < arr[i][j]) result = arr[i][j];
      }
   }
   cout << '\n' << '\n';
   for (int i = 0; i < b; i++) {
      for (int j = 0; j < a; j++) {
         cout << arr[i][j] << ' ';
      }
      cout << '\n';
   }
   cout << result - 1 << '\n';
   return 0;
}
