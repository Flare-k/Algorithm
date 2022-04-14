#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 11
using namespace std;

int N;
int P[MAX]; // 인구 수
vector<int> graph[MAX];
bool used[MAX];
bool visit[MAX];
int answer = 21e8;

bool checkConnection(int v, int size, bool flag) {
    fill(visit, visit + MAX, false);
    queue<int> q;
    q.push(v);
    visit[v] = true;
    int cnt = 1;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int next : graph[now]) {
            if (used[next] != flag || visit[next]) continue;
            cnt++;
            visit[next] = true;
            q.push(next);
        }
    }

    if (size == cnt) return true;
    return false;
}

bool checkFlag() {
    vector<int> a, b;

    for (int i = 1; i <= N; i++) {
        if (used[i]) a.push_back(i);
        else b.push_back(i);
    }

    if (a.empty() || b.empty()) return false;
    if (!checkConnection(a.front(), a.size(), true)) return false;
    if (!checkConnection(b.front(), b.size(), false)) return false;

    return true;
}

void run(int level, int start) {
    if (level >= 1) {
        if (checkFlag()) {
            int A = 0;
            int B = 0;

            for (int i = 1; i <= N; i++) {
                if (used[i]) A += P[i];
                else B += P[i];
            }

            answer = min(answer, abs(A - B));
        }

    }

    for (int i = start; i <= N; i++) {
        if (used[i]) continue;

        used[i] = true;
        run(level + 1, i + 1);
        used[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
    }

    int num, next;
    for (int cur = 1; cur <= N; cur++) {
        cin >> num;
        for (int j = 0; j < num; j++) {
            cin >> next;
            graph[cur].push_back(next);
        }
    }

    run(0, 1);

    if (answer != 21e8) cout << answer << '\n';
    else cout << -1 << '\n';

	return 0;
}