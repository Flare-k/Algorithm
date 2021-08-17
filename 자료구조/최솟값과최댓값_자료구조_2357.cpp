#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    int from, to;
};

vector<int> arr;
vector<int> maxtree;
vector<int> mintree;
vector<Node> fromto;


// 트리 초기화
int init(int node, int start, int end, bool isMax) {
    
    if (start == end)  {
        if (!isMax) {
            return mintree[node] = arr[start];
        }
        else {
            return maxtree[node] = arr[start];
        }
    }

    int mid = (start + end) / 2;
    int left = init(node * 2, start, mid, isMax);
    int right = init(node * 2 + 1, mid + 1, end, isMax);

    if (!isMax) {
        mintree[node] = min(left, right);
        return mintree[node];
    }
    else {
        maxtree[node] = max(left, right);
        return maxtree[node];
    }
}

int cmp(int node, int start, int end, int left, int right, bool isMax) {
    if (left > end || right < start) {
        if (!isMax) return 21e8;
        else return -21e8;
    }

    if (left <= start && end <= right) {
        if (!isMax) return mintree[node];
        else return maxtree[node];
    }

    int mid = (start + end) / 2;
    int leftValue = cmp(node * 2, start, mid, left, right, isMax);
    int rightValue = cmp(node * 2 + 1, mid + 1, end, left, right, isMax);

    if (!isMax) return min(leftValue, rightValue);
    else return max(leftValue, rightValue);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    int height = (int)ceil(log2(N));
    int treeSize = (1 << (height + 1));

    mintree.resize(treeSize);
    maxtree.resize(treeSize);

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

    init(1, 0, N - 1, false);
    init(1, 0, N - 1, true);

    for (auto cmd : fromto) {
        int from = cmd.from - 1;
        int to = cmd.to - 1;

        int minn = cmp(1, 0, N - 1, from, to, false);
        int maxx = cmp(1, 0, N - 1, from, to, true);

        cout << minn << ' ' << maxx << '\n';
    }

    return 0;
}