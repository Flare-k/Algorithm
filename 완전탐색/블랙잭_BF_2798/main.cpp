#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
이제 플레이어는 제한된 시간 안에 N장의 카드 중에서 3장의 카드를 골라야 한다.
블랙잭 변형 게임이기 때문에, 플레이어가 고른 카드의 합은 M을 넘지 않으면서 M과
최대한 가깝게 만들어야 한다.

N장의 카드에 써져 있는 숫자가 주어졌을 때, M을 넘지 않으면서 M에 최대한 가까운
카드 3장의 합을 구해 출력하시오.
*/

int N, M;
vector<int> check;
void checkFunc() {
   for (int i = 0; i < 3; i++) {
      check.push_back(1);
   }
   for (int i = 3; i < N; i++) {
      check.push_back(0);
   }
   sort(check.begin(), check.end());
}
void init() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
}
int main() {
   init();
   cin >> N >> M;
   int card[N];

   for (int i = 0; i < N; i++) {
      cin >> card[i];
   }
   checkFunc();

   vector<int> ans;
   do {
      int sum = 0;
      for (int i = 0; i < N; i++) {
         if (check[i] == 1) {
            sum += card[i];
         }
      }
      ans.push_back(sum);
   } while (next_permutation(check.begin(), check.end()));

   int max = 0;
   for (int i = 0; i < ans.size(); i++) {
      if (max < ans[i] && ans[i] <= M) {
         max = ans[i];
      }
   }
   cout << max << endl;
   return 0;
}