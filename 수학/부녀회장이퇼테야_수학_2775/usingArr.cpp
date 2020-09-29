#include <iostream>
using namespace std;

const int MAX = 14 + 1;
int home[MAX][MAX];

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int n;
   cin >> n;  // 총 반복 횟수
   for (int i = 1; i <= 14; i++) {
      home[0][i] = i;
      home[i][1] = 1;
   }
   while (n--) {
      int floor, number;  // 층, 호수
      cin >> floor >> number;
      for (int i = 1; i <= 14; i++) {
         for (int j = 2; j <= 14; j++) {
            home[i][j] = home[i][j - 1] + home[i - 1][j];
         }
      }
      cout << home[floor][number] << endl;
   }

   return 0;
}
