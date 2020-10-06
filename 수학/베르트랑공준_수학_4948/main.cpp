#include <iostream>
using namespace std;
const int MAX = 1000000 + 1;
int arr[MAX];

void erathosthenes() {
   arr[0] = arr[1] = 0;
   for (int i = 2; i < MAX; i++) {
      arr[i] = i;  // MAX만큼 배열에 모두 초기화 해준다.
   }

   for (int i = 2; i <= MAX; i++) {
      if (arr[i] == 0) continue;  //이미 체크된 수의 배수는 확인하지 않는다.
      for (int j = i + i; j <= MAX;
           j += i)  // i를 제외한 i의 배수들은 0으로 체크한다.
         arr[j] = 0;
   }
}

int main() {
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int n;

   erathosthenes();

   while (1) {
      int cnt = 0;
      cin >> n;
      if (n == 0) break;
      for (int i = n+1; i <= 2 * n; i++) {
         if (arr[i] != 0) cnt++;
      }
      cout << cnt << endl;
   }
   return 0;
}
