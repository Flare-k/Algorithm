#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;

const int target = 123456789;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num, start = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> num;

            if (num == 0) num = 9;

            start = (start * 10) + num;
        }
    }

    queue<int> q;
    map<int, int> m;

    q.push(start);
    m[start] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        string seq = to_string(cur);

        if (cur == target) break;

        int z = seq.find('9');
        int x = z / 3;
        int y = z % 3;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 and nx < 3 and ny >= 0 and ny < 3) {
                string tmp = seq;
                swap(tmp[x * 3 + y], tmp[nx * 3 + ny]);

                int next = stoi(tmp);

                if (!m.count(next)) {
                    m[next] = m[cur] + 1;
                    q.push(next);
                }
            }
        }
    }

    if (!m.count(target)) cout << - 1 << '\n';
    else cout << m[target] << '\n';

    return 0;
}