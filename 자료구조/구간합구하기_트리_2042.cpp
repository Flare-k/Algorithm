#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#define ll long long
using namespace std;

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;

    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return sum(tree, node * 2, start, mid, left, right) + sum(tree, node * 2 + 1, mid + 1, end, left, right);
}

void update(vector<ll> &tree, int node, int start, int end, int idx, ll diff) {
    if (!(start <= idx && idx <= end)) return;

    tree[node] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, node * 2, start, mid, idx, diff);
        update(tree, node * 2 + 1, mid + 1, end, idx, diff);
    }
}

// 트리 초기화
ll init(vector<ll> &arr, vector<ll> &tree, int node, int start, int end) {
    
    if (start == end)  return tree[node] = arr[start];

    int mid = (start + end) / 2;

    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K;
    cin >> N >> M >> K;     // 5

    vector<ll> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];      // 1, 2, 3, 4, 5
    }

    int h = (int)ceil(log2(N));
    int treeSize = (1 << (h + 1));
    vector<ll> tree(treeSize);

    init(arr, tree, 1, 0, N - 1);

    int iter = M + K;
    ll a, b, c;

    while (iter--) {
        cin >> a >> b >> c;

        if (a == 1) {
            ll diff = c - arr[b - 1];
            arr[b - 1] = c;

            update(tree, 1, 0, N - 1, b - 1, diff);
        }
        else if (a == 2) {
            cout << sum(tree, 1, 0, N - 1, b - 1, c - 1) << '\n';
            
        }
    }

    return 0;
}