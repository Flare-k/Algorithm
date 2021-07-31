#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int maxx = 0;
const int MAX = 1000001;
bool check[MAX][11];
int K, M;
string target;

struct Node {
    string num;
    int level;
};

void bfs() {
    queue<Node> q;
    q.push({target, 0});

    while (!q.empty()) {
        Node now = q.front();
        q.pop();
        
        string str = now.num;

        if (now.level == K) {
            maxx = max(maxx, stoi(str));
            continue;
        }

        for (int i = 0; i < M - 1; i++) {
            for (int j = i + 1; j < M; j++) {
                swap(str[i], str[j]);

                if (str.front() == '0' || check[stoi(str)][now.level + 1]) {
                   swap(str[i], str[j]);
                   continue;
                }

                q.push({str, now.level + 1});
                check[stoi(str)][now.level + 1] = true;
                swap(str[i], str[j]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> target >> K;
    M = target.length();

    bfs();

    if (maxx != 0) cout << maxx;
    else cout << -1;

    return 0;
}