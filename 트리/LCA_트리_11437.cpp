/*
    LCA(Lowest Common Ancestor)
    : 두 노드의 공통된 조상 중에서 가장 가까운 조상을 찾는 것 (가장 가까운 조상 = 가장 낮은 조상)
    1. 모든 노드에 대한 깊이를 계산한다
    2. 최소 공통 조상을 찾을 두 노드를 매번 확인한다.
        2-1. 먼저 두 노드의 깊이가 동일하도록 거슬러 올라간다.
        2-2. 이후에 부모가 같아질 때까지 반복적으로 두 노드의 부모 방향으로 거슬러 올라간다. O(N) -> O(logN)으로 줄일 수 있다.
    3. 모든 LCA(a, b) 연산에 대하여 2번의 과정을 반복한다.

    DFS를 이용하여 모든 노드에 대해 깊이를 계산할 수 있다.
    // O(NM)
*/

#include <iostream>
#include <vector>
#include <cmath>
#define MAX 100002
using namespace std;

int N, M;
int parent[MAX][20];
int depth[MAX];
int visit[MAX];
vector<int> graph[MAX];
int MAXH;

int lca(int a, int b) {
    if (depth[a] > depth[b]) swap(a, b);

    for (int i  = MAXH; i >= 0; i--) {
        if (depth[b] - depth[a] >= (1 << i)) b = parent[b][i];

    }
    if (a == b) return a;

    for (int i  = MAXH; i >= 0; i--) {
        if (parent[a][i] != parent[b][i]) {
            a = parent[a][i];
            b = parent[b][i];
        }
    }
    return parent[a][0];
}

void dfs(int x, int d) {
    visit[x] = true;
    depth[x] = d;
    for (int y : graph[x]) {
        if (visit[y]) continue;
        parent[y][0] = x;
        dfs(y, d + 1);
    }
}

void setParent() {
    dfs(1, 0);
    for (int i = 1; i <= MAXH; i++) {
        for (int j = 1; j <= N; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    MAXH = (int)floor(log2(N));
    setParent();
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}