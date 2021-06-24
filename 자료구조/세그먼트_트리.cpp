#include <iostream>
#include <vector>
#define ll long long
using namespace std;

/*
왼쪽 자식 노드 : node * 2
오른쪽 자식 노드: node * 2 + 1

tree 배열 -> 세그먼트 트리가 만들어지는 배열
arr 배열 -> 처음에 입력받아 생성된 배열
*/

ll sum(vector<ll> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) return 0;

    if (left <= start && end <= right) return tree[node];

    int mid (start + end) / 2;
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
    int n;
    cin >> n;               // 5

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];      // 1, 2, 3, 4, 5
    }

    int h = (int)ceil(log2(n));
    int treeSize = (1 << (h + 1));

    vector<ll> tree(treeSize);


    return 0;
}