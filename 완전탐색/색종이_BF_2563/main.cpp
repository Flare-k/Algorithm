#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int n;
const int MAX = 100 + 1;
int arr[MAX][MAX];

void init() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
}
int main() {
   init();
   cin >> n;
   for (int i = 0; i < n; i++) {
      int x, y;
      cin >> x >> y;
      for (int i = y + 1; i <= y + 10; i++) {
         for (int j = x + 1; j <= x + 10; j++) {
            arr[i][j] = 1;
         }
      }
   }
   int answer = 0;
   for (int i = 1; i < MAX; i++) {
      for (int j = 1; j < MAX; j++) {
         if (arr[i][j]) {
            answer++;
         }
      }
   }
   cout << answer << endl;

   return 0;
}