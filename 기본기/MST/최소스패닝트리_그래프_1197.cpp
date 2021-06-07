#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

const int MAX = 100001;
int arr[MAX];

struct Node {
    int from, to, value;
};

bool cmp(Node& a, Node& b) {
    if (a.value < b.value) return true;
    return false;
}

int getBoss(int n) {
    if (arr[n] == 0) return n;

    int res = getBoss(arr[n]);
    arr[n] = res;

    return res;
}

void setGroup(int n1, int n2) {
    int g1 = getBoss(n1);
    int g2 = getBoss(n2);

    if (g1 == g2) return;
    arr[g2] = g1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v, e;
    cin >> v >> e;

    vector<Node> vect;
    fill(arr, arr + MAX, 0);

    int from, to, value;
    for (int i = 0; i < e; i++) {
        cin >> from >> to >> value;
        vect.push_back({from, to, value});
    }

    sort(vect.begin(), vect.end(), cmp);

    int sum = 0;
    int cnt = 0;
    for (Node node : vect) {
        if (getBoss(node.from) != getBoss(node.to)) {
            cnt++;
            sum += node.value;
            setGroup(node.from, node.to);

            if (cnt == v - 1) break;
        }
    }

    cout << sum;

    return 0;
}