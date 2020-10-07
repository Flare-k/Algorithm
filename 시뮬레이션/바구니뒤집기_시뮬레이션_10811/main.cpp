#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   int N, M;
   cin >> N >> M;
   int arr[N + 1];
   for (int i = 1; i <= N; i++) {
      arr[i] = i;
   }
   for (int i = 0; i < M; i++) {
      int a, b;
      stack<int> tmp;
      cin >> a >> b;
      for (int j = a; j <= b; j++) {
         tmp.push(arr[j]);
      }
      while (!tmp.empty()) {
         arr[a] = tmp.top();
         tmp.pop();
         a++;
      }

      // reverse(&arr[a], &arr[b + 1]);   # #include <cstdio> -> 역순으로 배치
   }

   for (int i = 1; i <= N; i++) cout << arr[i] << " ";

   return 0;
}