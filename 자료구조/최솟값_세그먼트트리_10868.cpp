#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    int from, to;
};

vector<int> arr;
vector<int> mintree;
vector<Node> fromto;

// 트리 초기화
int init(int node, int start, int end) {
    
    if (start == end) return mintree[node] = arr[start];

    int mid = (start + end) / 2;
    int left = init(node * 2, start, mid);
    int right = init(node * 2 + 1, mid + 1, end);

    mintree[node] = min(left, right);
    return mintree[node];
}

int cmp(int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 21e8;

    if (left <= start && end <= right) return mintree[node];

    int mid = (start + end) / 2;
    int leftValue = cmp(node * 2, start, mid, left, right);
    int rightValue = cmp(node * 2 + 1, mid + 1, end, left, right);

    return min(leftValue, rightValue);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int height = (int)ceil(log2(N));
    int treeSize = (1 << (height + 1));

    mintree.resize(treeSize);

    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        arr.push_back(num);
    }

    int f, t;
    for (int i = 0; i < M; i++) {
        cin >> f >> t;
        fromto.push_back({f, t});
    }

    init(1, 0, N - 1);

    for (auto cmd : fromto) {
        int from = cmd.from - 1;
        int to = cmd.to - 1;

        int minn = cmp(1, 0, N - 1, from, to);

        cout << minn << '\n';
    }

    return 0;
}