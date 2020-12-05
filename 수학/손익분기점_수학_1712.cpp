#include <algorithm>
#include <iostream>

using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   long long A, B, C;
   cin >> A >> B >> C;
   int cnt = 1;
   if (B >= C) {
      cout << -1 << endl;
      return 0;
   }
   // 노트북 한 대당 순이익은 C-B만원이다.
   cout << A / (C - B) + 1 << endl;
   return 0;
}