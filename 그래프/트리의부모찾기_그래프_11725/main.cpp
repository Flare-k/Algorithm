#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define endl "\n"
#define INF 0x7fffffff
#define MAX 100001
using namespace std;
vector<int> arr[MAX];
int visit[MAX] = {
    0,
};
bool check[MAX];
void DFS(int n) {
   check[n] = true;
   for (int i = 0; i < arr[n].size(); i++) {
      int next = arr[n][i];
      if (!check[next]) {
         visit[next] = n;
         DFS(next);
      }
   }
}

int main() {
   int n;
   cin >> n;
   visit[0] = 0;
   visit[1] = 0;
   for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      /*
      if (!visit[b] && b != 1) {
         visit[b] = a;
      } else {
         visit[a] = b;
      }*/
      arr[a].push_back(b);
      arr[b].push_back(a);
   }
   DFS(1);

   for (int i = 2; i <= n; i++) {
      cout << visit[i] << endl;
   }

   return 0;
}
