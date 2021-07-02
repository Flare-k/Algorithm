#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100001;
bool visit[MAX];
int acc[MAX];

void run(int N, int K) {
    queue<int> q;
    q.push(N);
    visit[N] = true;
    acc[N] = 0;

    while (!q.empty()) {
        if (visit[K]) break;
        
        int now = q.front();
        q.pop();

        if (now * 2 < MAX && !visit[now * 2]) {
            q.push(now * 2);
            visit[now * 2] = true;
            acc[now * 2] = acc[now];    // 비용이 0이니 먼저 체크해준다. 1 2 = 0
        }

        if (now - 1 >= 0 && !visit[now - 1]) {
            q.push(now - 1);
            visit[now - 1] = true;
            acc[now - 1] = acc[now] + 1;
        }

        if (now + 1 < MAX && !visit[now + 1]) {
            q.push(now + 1);
            visit[now + 1] = true;
            acc[now + 1] = acc[now] + 1;
        }

    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;
    
    run(N, K);

    cout << acc[K];

    return 0;
}