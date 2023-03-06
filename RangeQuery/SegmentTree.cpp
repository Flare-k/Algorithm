/* ------------------------------------------------------------------------
      값을 변경하지 않는 경우     |        값을 변경하는 경우
1차원      prefix query               binary indexed tree (Fenwick tree)
         sparse table                 segment tree
                                    sqrt-decomposition

2차원   querymed-area table           binary indexed tree (Fenwick tree)
                                        segment tree
                                    sqrt-decomposition
----------------------------------------------------------------------------
*/
/*
    * Segment Tree *
    : 주어지는 연속된 데이터에 대한 구간 연산(update, query)을 O(logN) 시간에 할 수 있는 자료구조
    - update: 특정 위치(또는 구간)에 대한 업데이트를 O(logN)에 가능
    - query : 구간에 대한 연산을 O(logN)에 계산
    
    Segment Tree는 root부터 차례대로 1부터 시작하는 번호를 부여한다.
    번호가 부여되는 규칙이 있기 때문에 left, right 포인터를 따로 할당하지 않아도 됨.
    Complete tree의 특성을 이용한다.
        - 2^0
        - 2^1 ~
        - 2^2 ~
        - 2^3 ~
        - ...
    * 부모에서 자식으로 내려가는 경우
        2n, 2n+1
    * 자식에서 부모로 올라가는 경우
        (2n)/2, (2n+1)/2

    2N <= 노드들의 개수 <= 4N
*/

#include <iostream>
#include <vector>
using namespace std;


// arr: 초기 배열
// tree: 세그먼트 트리
// node: 세그먼트 트리 노드 번호
// node가 담당하는 합의 범위가 start ~ end


long long init(vector<long long> &arr, vector<long long> &tree, int node, int start, int end) {
    if (start == end)    // 노드가 리프 노드인 경우
        return tree[node] = arr[start];    // 배열의 그 원소를 가져야 함

    int mid = (start + end) / 2;

    // 구간 합을 구하는 경우
    return tree[node] = init(arr, tree, node * 2, start, mid) + init(arr, tree, node * 2 + 1, mid + 1, end);

    // 구간의 최솟값을 구하는 경우도 비슷하게 해줄 수 있다.
    // return tree[node] = min(init(arr, tree, node * 2, start, mid), init(arr, tree, node * 2 + 1, mid + 1, end));
}

long long query(vector<long long> &tree, int node, int start, int end, int left, int right) {
    // case 1: [start, end] 앞 뒤에 [left, right]가 있는 경우,
    // 겹치지 않기 때문에 탐색을 더 이상 할 필요가 없다.
    if (left > end || right < start) return INT_MAX;

    // case 2: [start, end]가 [left, right]에 포함
    if (left <= start && end <= right) return tree[node];

    // case 3, 4: 왼쪽 자식과 오른쪽 자식을 루트로 하는 트리에서 다시 탐색 시작
    int mid = (start + end) / 2;
    return query(tree, node*2, start, mid, left, right) + query(tree, node*2+1, mid+1, end, left, right);
}

void update(vector<long long> &tree, int node, int start, int end, int index, long long diff) {
    if (index < start || index > end) return;    // case 2
    tree[node] = tree[node] + diff;    // case 1

    // 리프 노드가 아닌 경우 자식도 변경해줘야 하기 때문에,
    // 리프 노드인지 검사를 하고 아래 자식 노드를 갱신해준다.
    if (start != end) {
        int mid = (start + end) / 2;
        update(tree,node*2, start, mid, index, diff);
        update(tree,node*2+1, mid+1, end, index, diff);
    }
}

int main() {
    int N;
    vector<long long> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    N = arr.size();
    vector<long long> tree(4 * N);
    init(arr, tree, 1, 0, N - 1);
    return 0;
}