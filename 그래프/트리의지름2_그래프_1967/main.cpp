#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <utility>
#include <vector>
#define endl "\n"
#define INF 0x7fffffff
#define MAX 10001
using namespace std;
vector<pair<int, int> > arr[MAX];

bool visit[MAX];
int dist[MAX];

void BFS(int n) {
   queue<int> q;
   q.push(n);
   visit[n] = true;
   while (!q.empty()) {
      int node = q.front();
      q.pop();
      for (int i = 0; i < arr[node].size(); i++) {
         int next = arr[node][i].first;
         if (!visit[next]) {
            dist[next] = dist[node] + arr[node][i].second;
            q.push(next);
            visit[next] = true;
            // cout << "dist[" << next << "] = " << dist[next] << endl;
            // 1~3의 거리는... 노드 1과 3의 거리 = 노드 1의 거리 + 노드 1과
            // 3의 가중치
         }
      }
   }
}

int main() {
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   int n, temp;
   cin >> n;
   temp = n;
   while (1) {
      int from, to, weight;
      cin >> from >> to >> weight;
      arr[from].push_back(make_pair(to, weight));
      arr[to].push_back(make_pair(from, weight));
      if (to == temp) break;
   }
   // 임의로 설정한 루트 1번으로부터의 거리를 구하기 위한 bfs탐색
   BFS(1);

   int start = 1;
   for (int i = 2; i <= n; i++) {
      if (dist[i] > dist[start]) {
         start = i;
      }
   }
   memset(dist, 0, sizeof(dist));
   memset(visit, false, sizeof(visit));

   BFS(start);
   int ans = dist[1];
   for (int i = 2; i <= n; i++) {
      if (ans < dist[i]) {
         ans = dist[i];
      }
   }
   cout << ans;

   return 0;
}
/*
12
1 2 3
1 3 2
2 4 11
3 5 5
3 6 9
4 7 15
4 8 7
5 9 1
5 10 4
6 11 6
6 12 10

*/