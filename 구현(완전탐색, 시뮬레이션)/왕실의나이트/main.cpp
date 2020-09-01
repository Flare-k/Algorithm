#include <iostream>
#include <string>
#include <vector>
using namespace std;

int step[8][2] = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1},
                  {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
// 나이트의 이동거리를 고정시켜놓는 것이 중요하다.
int main() {
   string location;
   // a = 49
   cin >> location;
   int row = location[1] - '0';
   int col = location[0] - 'a' + 1;

   int cnt = 0;
   for (int i = 0; i < 8; i++) {
      int nx = row + step[i][0];
      int ny = col + step[i][1];

      if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8) cnt++;
   }
   cout << cnt << endl;
   return 0;
}