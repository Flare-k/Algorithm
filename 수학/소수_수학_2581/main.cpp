#include <algorithm>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;
const int MAX = 10000 + 1;
int arr[MAX];
void erathosthenes() {
   arr[0] = 0;
   arr[1] = 0;
   for (int i = 2; i <= MAX; i++) {
      arr[i] = i;
   }
   for (int i = 2; i <= MAX; i++) {
      if (arr[i] == 0) continue;
      for (int j = i + i; j <= MAX; j += i) {
         arr[j] = 0;
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int n, m;
   cin >> n >> m;
   erathosthenes();
   int sum = 0;
   vector<int> ans;
   for (int i = n; i <= m; i++) {
      if (arr[i]) {
         sum += arr[i];
         ans.push_back(arr[i]);
      }
   }
   sort(ans.begin(), ans.end());
   if (ans.size() == 0) {
      cout << -1;
      return 0;
   }
   cout << sum << endl;
   cout << ans[0];
   return 0;
}