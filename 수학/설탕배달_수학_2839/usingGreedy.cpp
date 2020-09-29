#include <algorithm>
#include <iostream>
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int sugar;          // 설탕의 무게
   int quo = 0;        // 5로 나눈 몫
   int remainder = 0;  // 나머지
   int ans = 0;        // 최종 결과 값
   cin >> sugar;       // 11이라 가정
   quo = sugar / 5;    // 2

   while (quo >= 0) {
      remainder = 0;
      ans = 0;
      if (quo > 0) {
         remainder = sugar - 5 * quo;  // 1 -> 6
         ans = quo;                    // ans = 2 -> 1
      } else {
         remainder = sugar;
      }
      ans += remainder / 3;  // ans = 2 -> ans = 1+2 = 3
      remainder %= 3;        // remainder = 1 -> remainder = 0
      if (remainder == 0) {  // 3으로까지 나눠떨어지게 되면 ans를 출력한다.
         cout << ans;
         break;
      }
      quo--;  // 2 -> 1
   }
   if (remainder != 0) cout << -1;

   return 0;
}
