/*
 그래프의 아이디어를 이용한다.
 */
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 100001;
bool visited[MAX];
int dist[MAX];

void BFS(int n) {
    visited[n] = true;
    dist[n] = 0;
    queue<int> q;
    q.push(n);
    
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now - 1 >= 0) {
            if (!visited[now - 1]) {
                q.push(now - 1);
                visited[now - 1] = true;
                dist[now - 1] = dist[now] + 1;
            }
        }
        if (now + 1 < MAX) {
            if (!visited[now + 1]) {
                q.push(now + 1);
                visited[now + 1] = true;
                dist[now + 1] = dist[now] + 1;
            }
        }
        if (now * 2 < MAX) {
            if (!visited[now * 2]) {
                q.push(now * 2);
                visited[now * 2] = true;
                dist[now * 2] = dist[now] + 1;
            }
        }
    }
}

int main() {
   int a, b;
   cin >> a >> b;
   BFS(a);
   cout << dist[b] << '\n';
   return 0;
}
