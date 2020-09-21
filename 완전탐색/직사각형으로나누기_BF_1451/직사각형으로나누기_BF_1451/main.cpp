#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int r, c;
const int MAX = 10001;
int arr[MAX][MAX];
long long s[MAX][MAX];

long long sum(int x1, int y1, int x2,
              int y2) {  //세가지의 경우를 더하는 알고리즘.
   return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
}

int main() {
   cin >> r >> c;
   for (int i = 1; i <= r; i++) {
      string temp;
      cin >> temp;
      for (int j = 1; j <= c; j++) {
         arr[i][j] = temp[j - 1] - '0';
      }
   }  //행렬 입력받기

   for (int i = 1; i <= r; i++) {
      for (int j = 1; j <= c; j++) {
         s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + arr[i][j];
      }
   }
   //---------------
   long long ans = 0;
   for (int i = 1; i <= c - 2; i++) {
      for (int j = i + 1; j <= c - 1; j++) {
         long long r1 = sum(1, 1, r, i);
         long long r2 = sum(1, i + 1, r, j);
         long long r3 = sum(1, j + 1, r, c);
         if (ans < r1 * r2 * r3) {
            ans = r1 * r2 * r3;
         }
      }
   }
   for (int i = 1; i <= r - 2; i++) {
      for (int j = i + 1; j <= r - 1; j++) {
         long long r1 = sum(1, 1, i, c);
         long long r2 = sum(i + 1, 1, j, c);
         long long r3 = sum(j + 1, 1, r, c);
         if (ans < r1 * r2 * r3) {
            ans = r1 * r2 * r3;
         }
      }
   }
   for (int i = 1; i <= r - 1; i++) {
      for (int j = 1; j <= c - 1; j++) {
         long long r1 = sum(1, 1, r, j);
         long long r2 = sum(1, j + 1, i, c);
         long long r3 = sum(i + 1, j + 1, r, c);
         if (ans < r1 * r2 * r3) {
            ans = r1 * r2 * r3;
         }
         r1 = sum(1, 1, i, j);
         r2 = sum(i + 1, 1, r, j);
         r3 = sum(1, j + 1, r, c);
         if (ans < r1 * r2 * r3) {
            ans = r1 * r2 * r3;
         }
         r1 = sum(1, 1, i, c);
         r2 = sum(i + 1, 1, r, j);
         r3 = sum(i + 1, j + 1, r, c);
         if (ans < r1 * r2 * r3) {
            ans = r1 * r2 * r3;
         }
         r1 = sum(1, 1, i, j);
         r2 = sum(1, j + 1, i, c);
         r3 = sum(i + 1, 1, r, c);
         if (ans < r1 * r2 * r3) {
            ans = r1 * r2 * r3;
         }
      }
   }
   cout << ans << '\n';
   return 0;
}
