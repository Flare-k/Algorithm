#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 501;
int N, M;
int arr[MAX][MAX];
int dp[MAX][MAX];

struct Node {
    int i, j, v;
};

vector<Node> node;

bool cmp(Node& a, Node& b) {
    if (a.v > b.v) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            node.push_back({i, j, arr[i][j]});
        }
    }

    sort(node.begin(), node.end(), cmp);

    for (int i = 0; i < node.size(); i++) {
        int r = node[i].i;
        int c = node[i].j;

        if (r == 0 && c == 0) {
            dp[r][c] = 1;
            continue;
        }

        if (arr[r][c] < arr[r-1][c]) dp[r][c] += dp[r-1][c];
        if (arr[r][c] < arr[r+1][c]) dp[r][c] += dp[r+1][c];
        if (arr[r][c] < arr[r][c-1]) dp[r][c] += dp[r][c-1];
        if (arr[r][c] < arr[r][c+1]) dp[r][c] += dp[r][c+1];
    }

    cout << dp[N-1][M-1];

    return 0;
}