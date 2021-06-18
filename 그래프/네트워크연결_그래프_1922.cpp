#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 최소 스패닝 트리
int vect[1001];
struct Node {
    int from, to, node;
};

int getBoss(int n) {
    if (vect[n] == 0) return n;

    int ret = getBoss(vect[n]);
    vect[n] = ret;
    return ret;
}

void setGroup(int n1, int n2) {
    int g1 = getBoss(n1);
    int g2 = getBoss(n2);

    if (g1 == g2) return;
    vect[g2] = g1;
}


bool cmp(Node a, Node b) {
    if (a.node < b.node) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Node> route;

    int from , to, node;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> node;

        route.push_back({from, to, node});
    }

    sort(route.begin(), route.end(), cmp);

    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < m; i++) {
        int from = route[i].from;
        int to = route[i].to;
        int node = route[i].node;

        if (getBoss(from) != getBoss(to)) {
            setGroup(from, to);
            sum += node;
            cnt++;
        }

        if (cnt == n - 1) break;
    }

    cout << sum << '\n';

    return 0;
}