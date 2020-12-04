#include <algorithm>
#include <iostream>
#include <vector>
#define endl "\n"
using namespace std;

int n;  // 컴퓨터의 수
const int MAX = 10000 + 1;
int cnt = 0;
vector<int> network[MAX];
bool visit[MAX];

void DFS(int n) {
   visit[n] = true;
   cnt++;
   for (int i = 0; i < network[n].size(); i++) {
      int nextNode = network[n][i];
      if (!visit[nextNode]) {
         DFS(nextNode);
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> n;
   int connect;
   cin >> connect;
   for (int i = 0; i < connect; i++) {
      int a, b;
      cin >> a >> b;
      network[a].push_back(b);
      network[b].push_back(a);
   }
   for (int i = 1; i <= n; i++) {
      if (!visit[i]) {
         cnt = -1;
         DFS(i);
         if(i == 1)
            cout << cnt;
      }
   }

   return 0;
}