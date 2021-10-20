#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1500051;
int dp[MAX];
int N;
struct Node {
    int T, P;
};

vector<Node> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    
    int T, P;
    for (int i = 0; i < N; i++) {
        cin >> T >> P;
        v.push_back({T, P});
    }

    for (int i = 0; i < v.size(); i++) {
        Node now = v[i];

        dp[i + now.T] = max(dp[i + now.T], dp[i] + now.P);
        dp[i + 1] = max(dp[i + 1], dp[i]);
    }

    cout << dp[N];

    return 0;
}