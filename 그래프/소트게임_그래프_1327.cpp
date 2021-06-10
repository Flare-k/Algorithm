#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
using namespace std;

int N, K;

struct Node {
    string str;
    int cnt;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    
    char ch;
    string str;
    for (int i = 0; i < N; i++) {
        cin >> ch;
        str += ch;
    }

    string target = str;
    sort(target.begin(), target.end());
    
    queue<Node> q;
    q.push({str, 0});
    map<string, bool> m;
    bool flag = false;
    
    while (!q.empty()) {
        string str = q.front().str;
        int cnt = q.front().cnt;
        q.pop();

        if (str == target) {
            cout << cnt;
            flag = true;
            break;
        }

        if (!m.count(str)) {
            m[str] = true;

            for (int i = 0; i <= N - K; i++) {
                string tmp = str.substr(i, K);  // i부터 K개
                reverse(tmp.begin(), tmp.end());

                q.push({str.substr(0, i) + tmp + str.substr(i + K) , cnt + 1});
            }
        }

    }

    if (!flag) cout << -1;

    return 0;
}

