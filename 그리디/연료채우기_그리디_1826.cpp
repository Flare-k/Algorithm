#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, a, b, L, P;

struct Node {
    int dist, oil;
};

bool cmp(Node a, Node b) {
    if (a.dist < b.dist) return true;
    return false;
}

priority_queue<int> pq;
vector<Node> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), cmp);

    cin >> L >> P;

    int curL = P;   // 현재 연료 양
    int curP = 0;   // 현재 연료 양으로 갈 수 있는 주유소 인덱스
    int cnt = 0;    // 주유소에 들린 횟수

    while (curL < L) {
        while (curP < n && v[curP].dist <= curL) {
            pq.push(v[curP++].oil);
        }

        if (pq.empty()) {
            cnt = -1;
            break;
        }

        curL += pq.top();
        pq.pop();
        cnt++;
    }

    cout << cnt << '\n';

    return 0;
}