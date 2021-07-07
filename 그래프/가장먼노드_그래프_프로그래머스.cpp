#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

/*
첫번째 시도 -> 플로이드 워셜 = 3중 for문이라 당연히 시간초관데 생각을 못했다..
두번째 시도 -> 거리라는 개념을 생각했고 BFS로 접근 = 정답!!
*/

const int MAX = 20001;
bool used[MAX];
int arr[MAX];

bool cmp(vector<int> a, vector<int> b) {
    if (a.front() < b.front()) return true;
    return false;
}

// BFS
void run(int n, int node, vector<vector<int>> vec) {
    queue<int> q;
    q.push(node);
    used[node] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < vec[v].size(); i++) {
            int next = vec[v][i];
            if (!used[next]) {
                arr[next] = arr[v] + 1;
                used[next] = true;
                q.push(next);
            }
        }
    }

}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    sort(edge.begin(), edge.end(), cmp);

    vector<vector<int>> vec(n + 1);
    
    // 양방향으로 갱신
    for (int i = 0; i < edge.size(); i++) {
        int x = edge[i][0];
        int y = edge[i][1];

        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        sort(vec[i].begin(), vec[i].end());
    }

    run(n, 1, vec);
    
    // 가장 먼 경우의 거리 체크
    int maxx = -21e8;
    for (int i = 1; i <= n; i++) {
        maxx = max(maxx, arr[i]);
    }

    // 가장 먼 경우가 몇 케이스가 있는지 체크
    for (int i = 1; i <= n; i++) {
        if (arr[i] == maxx) answer++;
    }

    return answer;
}

int main() {
    int ans = solution(6, {{3, 6},
                        {4, 3},
                        {3, 2},
                        {1, 3},
                        {1, 2},
                        {2, 4},
                        {5, 2}});

    cout << ans;

    return 0;
}