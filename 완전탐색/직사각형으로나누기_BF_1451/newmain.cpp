#include <algorithm>
#include <iostream>
using namespace std;

#define ll long long
int n, m;
ll ans = -1;
ll sum[110][110];

int main() {
   cin >> n >> m;

   char str[110];
   for (int i = 1; i <= n; i++) {
      cin >> str;
      for (int j = 1; j <= m; j++) {
         sum[i][j] = str[j - 1] - '0';
      }
   }

   // 합구하기
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         sum[i][j] =
             sum[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
      }
   }

   // 1~4까지
   for (int a = 1; a < n; a++) {
      for (int b = 1; b < m; b++) {
         ans = max(ans, sum[a][b] * (sum[n][b] - sum[a][b]) *
                            (sum[n][m] - sum[n][b]));
         ans = max(ans, sum[n][b] * (sum[a][m] - sum[a][b]) *
                            (sum[n][m] - sum[n][b] - sum[a][m] + sum[a][b]));
         ans = max(ans, sum[a][m] * (sum[n][b] - sum[a][b]) *
                            (sum[n][m] - sum[n][b] - sum[a][m] + sum[a][b]));
         ans = max(ans, sum[a][b] * (sum[a][m] - sum[a][b]) *
                            (sum[n][m] - sum[a][m]));
      }
   }

   // 5
   for (int a = 1; a <= m - 2; a++) {
      for (int b = a + 1; b <= m - 1; b++) {
         ans = max(ans, sum[n][a] * (sum[n][b] - sum[n][a]) *
                            (sum[n][m] - sum[n][b]));
      }
   }

   // 6
   for (int a = 1; a <= n - 2; a++) {
      for (int b = a + 1; b <= n - 1; b++) {
         ans = max(ans, sum[a][m] * (sum[b][m] - sum[a][m]) *
                            (sum[n][m] - sum[b][m]));
      }
   }

   cout << ans;
   return 0;
}