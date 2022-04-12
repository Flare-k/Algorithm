#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#define MAX 1000001
using namespace std;

int N, K;
int cnt;
int visit[MAX];
vector<int> v;

void value() {
    int val = K;
    v.push_back(val);

    while (val != N) {
        v.push_back(visit[val]);
        val = visit[val];
    }
}

void run() {
    int d[2] = {-1, 1};
    fill(visit, visit + MAX, -1);
    queue<int> q;
    q.push(N);
    visit[N] = N;

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            int now = q.front();
            q.pop();

            if (now == K) {
                value();
                return;
            }

            for (int j = 0; j < 2; j++) {
                int next = now + d[j];

                if ((next >= 0 && next < MAX) && visit[next] == -1) {
                    visit[next] = now;
                    q.push(next);
                }
            }

            int next = now * 2;
            if ((next >= 0 && next < MAX) && visit[next] == -1) {
                visit[next] = now;
                q.push(next);
            }
        }

        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    run();

    cout << cnt << '\n';

    reverse(v.begin(), v.end());

    for (int num : v) {
        cout << num << ' ';
    }

	return 0;
}
