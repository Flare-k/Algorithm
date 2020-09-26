#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*
간격이 x 이상인 구간으로 나눌수있는가로 알아보자.
간격은 for문을 돌리면서 하나씩 가고.. 제한은 집의 개수만큼
그러면서 이분법으로 나눠서 총 C번까지만..

*/
int N, C;
vector<int> share;
bool possible(int dist) {
   int cnt = 1;
   int prev = share[0];
   for (int i = 1; i < N; i++) {
      if (share[i] - prev >= dist) {
         cnt++;
         prev = share[i];
      }
   }
   if (cnt >= C) return true;
   return false;
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   cin >> N >> C;  // N: 집의 수, C: 공유기의 수
   for (int i = 0; i < N; i++) {
      int num;
      cin >> num;
      share.push_back(num);
   }
   sort(share.begin(), share.end());  // 1 2 4 8 9

   int left = 1;
   int right = share.back();
   int result = 0;

   while (left <= right) {
      int dist = (left + right) / 2;
      if (possible(dist)) {
         result = max(result, dist);
         left = dist + 1;
      } else
         right = dist - 1;
   }

   cout << result << endl;

   return 0;
}