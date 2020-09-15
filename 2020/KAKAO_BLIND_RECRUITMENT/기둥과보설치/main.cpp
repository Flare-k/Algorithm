/*
build_frame = [x, y, a, b]
x,y는 기둥/보를 설치/삭제할 교차점의 좌표 (가로좌표, 세로좌표)
a는 설치/삭제할 구조물의 종류 0:기둥, 1:보
b는 구조물을 설치할 지, 혹은 삭제할 지를 나타내면 0:삭제, 1:설치
바닥에 보 설치하는 경우 없음
구조물은 교차점 좌표를 기준으로 보는 오른쪽, 기둥은 위쪽 방향으로 설치/삭제

return 하는 배열을 가로(열) 길이가 3인 2차원 배열로, 각 구조물의 좌표를
담고있어야 한다. return하는 배열의 원소는 [x, y, a] 형식이다.
-> x좌표 기준으로 오름차순 정렬하며 x좌표가 같을 경우 y좌표 기준으로 오름차순
정렬하여 return
만약 (0,0,0,1)이면.. 인덱스는.. (4,0)인데.. (길이-  -기둥) x y
(1, 1, 1, 1) 이면.. 인덱스는.. (4,1)인데..
(2, 1, 0, 1) 이면.. 인덱스는.. (3,1)인데..
*/
#include <iostream>
#include <vector>
using namespace std;

bool gi[101][101] = {};
bool bo[101][101] = {};

bool check_gi(int x, int y, int n) {
   if (y == 0) return 1;
   if (gi[x][y - 1]) return 1;
   if (x > 0 && bo[x - 1][y]) return 1;
   if (x < n && bo[x][y]) return 1;

   return 0;
}

bool check_bo(int x, int y, int n) {
   if (gi[x][y - 1]) return 1;
   if (x < n && gi[x + 1][y - 1]) return 1;
   if (x > 0 && x < n && bo[x + 1][y] && bo[x - 1][y]) return 1;

   return 0;
}

vector<vector<int> > solution(int n, vector<vector<int> > build_frame) {
   vector<vector<int> > answer;

   for (int i = 0; i < build_frame.size(); i++) {
      int x, y, a, b;
      x = build_frame[i][0];
      y = build_frame[i][1];
      a = build_frame[i][2];
      b = build_frame[i][3];

      // 기둥 설치
      if (a == 0 && b == 1) {
         if (check_gi(x, y, n)) {
            gi[x][y] = 1;
         }
      }
      // 보 설치
      else if (a == 1 && b == 1) {
         if (check_bo(x, y, n)) {
            bo[x][y] = 1;
         }
      }
      // 기둥 삭제
      else if (a == 0 && b == 0) {
         bool can = 1;
         gi[x][y] = 0;

         if (y < n && gi[x][y + 1] && !check_gi(x, y + 1, n))
            can = 0;
         else if (y < n && bo[x][y + 1] && !check_bo(x, y + 1, n))
            can = 0;
         else if (x > 0 && bo[x - 1][y + 1] && y < n &&
                  !check_bo(x - 1, y + 1, n))
            can = 0;

         if (!can) gi[x][y] = 1;
      }
      // 보 삭제
      else if (a == 1 && b == 0) {
         bool can = 1;
         bo[x][y] = 0;

         if (gi[x][y] && !check_gi(x, y, n))
            can = 0;
         else if (x < n && gi[x + 1][y] && !check_gi(x + 1, y, n))
            can = 0;
         else if (x > 0 && bo[x - 1][y] && !check_bo(x - 1, y, n))
            can = 0;
         else if (x < n && bo[x + 1][y] && !check_bo(x + 1, y, n))
            can = 0;

         if (!can) bo[x][y] = 1;
      }
   }

   // answer에 기둥과 보 상태 넣기
   for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
         if (gi[i][j]) {
            answer.push_back({i, j, 0});
         }
         if (bo[i][j]) {
            answer.push_back({i, j, 1});
         }
      }
   }

   return answer;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n;
   cin >> n;
   vector<vector<int> > build_frame(8, vector<int>(4, 0));
   for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 4; j++) {
         int num;
         cin >> num;
         build_frame[i][j] = num;
      }
   }
   vector<vector<int> > res = solution(n, build_frame);

   for (int i = 0; i < solution(n, build_frame).size(); i++) {
      for (int j = 0; j < 3; i++) {
         cout << solution(n, build_frame)[i][j] << " ";
      }
      cout << endl;
   }

   return 0;
}
/*
5
1 0 0 1
1 1 1 1
2 1 0 1
2 2 1 1
5 0 0 1
5 1 0 1
4 2 1 1
3 2 1 1
*/