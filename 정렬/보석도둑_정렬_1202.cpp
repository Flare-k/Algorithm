#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K; // 보석의 수, 가방의 수

struct Node {
    int m, v;
};

bool cmp(Node& a, Node& b) {
    if (a.m < b.m) return true;
    return false;
}

vector<Node> jewelry;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int m, v;
        cin >> m >> v;
        jewelry.push_back({m, v});
    }

    vector<int> backpack(K, 0);

    for (int i = 0; i < K; i++) {
        cin >> backpack[i];
    }

    sort(jewelry.begin(), jewelry.end(), cmp);
    sort(backpack.begin(), backpack.end());

    long long sum = 0;
    int idx = 0;
    priority_queue<int> pq;
    for (int bp : backpack) {
        
        while (idx < N && jewelry[idx].m <= bp) {
            pq.push(jewelry[idx++].v);
        }

        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;

    return 0;
}