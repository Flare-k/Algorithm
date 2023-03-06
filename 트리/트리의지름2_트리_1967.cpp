#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 10001
using namespace std;

struct Node {
    int node, value;
};
int N;
int start, answer;
bool visited[MAX];
vector<Node> graph[MAX];

void BFS(int node, int value) {
    queue<Node> q;
    q.push({node, value});

    while (!q.empty()) {
        Node now = q.front();
        visited[now.node] = true;
        q.pop();

        if (answer < now.value) {
            answer = now.value;
            start = now.node;
        }

        for (int i = 0; i < graph[now.node].size(); i++) {
            int next = graph[node][i].node;
            if (visited[next]) continue;
            int nValue = value + graph[node][i].value;
            q.push({next, nValue});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    start = 0, answer = 0;
    memset(visited, false, sizeof(visited));
    BFS(1, 0);

    answer = 0;
    memset(visited, false, sizeof(visited));
    BFS(start, 0);

    cout << answer << '\n';

    return 0;
}
