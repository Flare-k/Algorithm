#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

struct Node {
    int node, value;
};
int N;
int start, answer;
bool visited[MAX];
vector<Node> graph[MAX];

void DFS(int node, int value) {
    if (visited[node]) return;
    visited[node] = true;

    if (answer < value) {
        answer = value;
        start = node;
    }

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i].node;
        int nValue = value + graph[node][i].value;
        DFS(next, nValue);
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
    DFS(1, 0);

    answer = 0;
    memset(visited, false, sizeof(visited));
    DFS(start, 0);

    cout << answer << '\n';

    return 0;
}
