#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int from, to;
};

int N;
vector<Node> v;

bool cmp(Node a, Node b) {
    if (a.from < b.from) return true;
    return false;
}

int dp[501];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;

    int from, to;
    for (int i = 0; i < N; i++) {
        cin >> from >> to;
        v.push_back({from, to});
    }

    sort(v.begin(), v.end(), cmp);
    int maxx = -21e8;

    for (int i = 0; i < v.size(); i++) {
        if (dp[i] == 0) dp[i] = 1;
        
        for (int j = 0; j < i; j++) {
            if (v[i].to > v[j].to) {
                if (dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
            }
        }

        maxx = max(maxx, dp[i]);
    }

    cout << N - maxx;

    return 0;
}