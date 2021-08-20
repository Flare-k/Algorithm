#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#define MAX 32001
using namespace std;

// 위상정렬 x 우선순위 큐

int n, m, inDegree[MAX];
vector<int> arr[MAX];

void topologySort() {
   priority_queue<int, vector<int>, greater<int>> q;    // 우선순위 큐(오름차순)
   int result[MAX];
   memset(result, 0, sizeof(result));
   
   for (int i = 1; i <= n; i++) {
      if (inDegree[i] == 0) q.push(i);
   }
   
   for (int i = 1; i <= n; i++) {
      if (q.empty()) return;

      int x = q.top();
      q.pop();

      result[i] = x;

      for (int j = 0; j < arr[x].size(); j++) {
         int y = arr[x][j];
         if (--inDegree[y] == 0) {
            q.push(y);
         }
      }
   }

   for (int i = 1; i <= n; i++) {
      cout << result[i] << " ";
   }

}

int main() {
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
        inDegree[b]++;
    }
   
   topologySort();

   return 0;
}