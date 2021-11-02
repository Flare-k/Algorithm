#include <iostream>
#include <queue>
#include <vector>
#define MAX 32000 + 1
using namespace std;

int n, m, inDegree[MAX];  // 진입차수:각 정점의 진입차수 정보를 담는다.
vector<int> a[MAX];

void topologySort() {
    int result[MAX];
    queue<int> q;
    // 대입 차수가 0인 노드를 큐에 삽입한다.
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    // 위상 정렬이 완전히 수행되려면 정확히 N개의 노드를 방문해야 한다.
    for (int i = 1; i <= n; i++) {
        // N개를 방문하기 전에 큐가 빈다면 사이클이 발생한 것
        int x = q.front();
        q.pop();
        result[i] = x;

        for (int j = 0; j < a[x].size(); j++) {
            int y = a[x][j];
            // 새롭게 진입차수가 0이 된 정점을 큐에 삽입한다.
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

    for (int i = 0; i < m; i++) {
        int pre, post;
        cin >> pre >> post;

        a[pre].push_back(post);
        inDegree[post]++;
    }

    topologySort();
    
    return 0;
}