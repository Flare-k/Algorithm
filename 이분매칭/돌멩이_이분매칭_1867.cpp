#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 501
using namespace std;

int N, K;
vector<int> arr[MAX];
bool visit[MAX];
int d[MAX];

bool dfs(int x) {
    for (int i = 0; i < arr[x].size(); i++) {
        int next = arr[x][i];

        if (visit[next]) continue;

        visit[next] = true;

        if (d[next] == 0 || dfs(d[next])) {
            d[next] = x;
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    int a, b;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        arr[a].push_back(b);
    }

    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        fill(visit, visit + MAX, false);

        if (dfs(i)) cnt++;
    }

    cout << cnt << '\n';

    return 0;
}