#include <iostream>
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};  // 북 동 남 서
/*
1. 현재 위치에서 현재 방향을 기준으로 왼쪽 방향(반시계 방향으로 90도 회전한
방향)부터 차례대로 갈 곳을 정한다.

2. 캐릭터의 바로 왼쪽 방향에 아직 가보지 않은 칸이 존재한다면, 왼쪽 방향으로
회전한 다음 왼쪽으로 한 칸을 전진한다. 왼쪽 방향에 가보지 않은 칸이 없다면, 왼쪽
방향으로 회전만 수행하고 1단계로 돌아간다.

3. 만약 네 방향 모두 이미 가본 칸이거나 바다로 되어 있는 칸인 경우에는, 바라보는
방향을 유지한 채로 한 칸 뒤로 가고 1단계로 돌아간다. 단, 이때 뒤쪽 방향이 바다인
칸이라 뒤로 갈 수 없는 경우에는 움직임을 멈춘다. 캐릭터가 방문한 칸의 수를
출력하는 프로그램을 만드시오.
- 0: 북
- 1: 동
- 2: 남
- 3: 서
<입력>
4 4
1 1 0
1 1 1 1
1 0 0 1
1 1 0 1
1 1 1 1
<출력>
3
*/
const int MAX = 50;
int arr[MAX][MAX];
bool visit[MAX][MAX];
int direction;
void turnLeft() {
   // 1. 왼쪽으로 회전
   direction--;
   if (direction == -1) direction = 3;
}
int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n, m;
   cin >> n >> m;  // 행 & 열

   int rowDot, colDot;
   cin >> rowDot >> colDot >> direction;  // 현재 좌표와 방향입력

   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> arr[i][j];
         visit[i][j] = false;
      }
   }
   visit[rowDot - 1][colDot - 1] = true;
   int cnt = 0;
   int turnTime = 0;
   while (1) {
      // 1. 왼쪽으로 회전
      turnLeft();
      int nx = rowDot + dx[direction];
      int ny = colDot + dy[direction];
      // 2-1. 캐릭터의 바로 왼쪽 방향에 아직 가보지 않은 칸이 존재한다면, 왼쪽
      // 방향으로 회전한 다음 왼쪽으로 한 칸을 전진한다.
      if (!visit[nx][ny] && arr[nx][ny] == 0) {
         visit[nx][ny] = true;
         rowDot = nx;
         colDot = ny;
         cnt++;
         turnTime = 0;
         continue;
      } else {
         // 2-2. 회전한 이후 정면에 가보지 않은 칸이 없거나 바다인 경우
         turnTime += 1;
      }
      // 3-1. 네 방향 모두 갈 수 없는 경우
      if (turnTime == 4) {
         int nx = rowDot - dx[direction];
         int ny = colDot - dy[direction];
         // 3-2. 뒤로 갈 수 있다면 이동하기
         if (arr[nx][ny] == 0) {
            rowDot = nx;
            colDot = ny;
         } else {
            break;
         }
         turnTime = 0;
      }
   }
   cout << cnt << endl;
   return 0;
}