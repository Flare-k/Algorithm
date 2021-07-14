#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 101;
bool visit[MAX];
int arr[MAX];
int answer[MAX];
int cnt = 0, idx = 0;

// 사이클 확인
void DFS(int node, int start) {
    int next = arr[node];

    if (visit[node]) {  // 만약 시작지점으로 돌아왔다면 
        if (node == start) {    // 현재 노드가 시작 노드값과 같은지 확인
            cnt++;
            answer[idx++] = start;
        }
    }
    else {  // 만약 시작점으로 돌아오지 않았다면 방문체크 & 다음 노드로..
        visit[node] = true;
        DFS(next, start);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        memset(visit, false, sizeof(visit));
        DFS(i, i);
    }

    cout << cnt << '\n';
    for (int i = 0; i < MAX; i++) {
        if (answer[i] != 0) cout << answer[i] << '\n';
        else break;
    }

    return 0;
}