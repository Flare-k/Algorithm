#include <iostream>
using namespace std;
/*
    BST; Binary Search Tree
    != Binary Search

    빠른 검색을 위한 알고리즘이다. 1) BST 2) Hash 두 가지가 가장 빠르다.
    BST, HASH 모두 O(logN) 속도이다. (HASH는 O(1)에 가깝다)

    많은 숫자들 중에 특정 숫자가 있는지 찾는다고 가정하자.
    4, 2, 9, 7, 15, 99
    1. init 과정
         4
       /   \
      2     9
           /  \
          7    15
                 \
                  99
    만약 1을 찾는다? 왼쪽으로 두 번 움직이고 없음을 확인
    만약 7을 찾는다? 오른쪽 한 번, 왼쪽 한 번 움직이고 확인 (총 두 번)

    ## 높이 수 만큼 반복하면 있는지 없는지 확인할 수 있다. ##
    1. 트리의 높이 h가 탐색 수
    2. 노드 수 = 7 = 2^h - 1
    2^h - 1 => log2(노드수) = h (이때 2는 밑 2를 의미한다)
    O(log2N) = 탐색 수 (이때 2는 밑 2를 의미한다)

    BST 구현 방법
    1. insert 함수 (init) - n의 시간이 걸림
    2. search 함수 - logn의 시간
    -> nlogn
*/

// 트리를 1차원 행렬에 구현해놓자. 작으면 2n, 크면 2n + 1

int tree[100];

void insert(int v) {
    int now = 1;

    while (1) {
        if (tree[now] == 0) {
            tree[now] = v;
            return;
        }

        // v가 현재 노드보드 크면 2n + 1
        if (tree[now] < v) {
            now = (now * 2) + 1;
        }
        // 작으면 2n
        else {
            now *= 2;
        }
    }
}

int find(int v) {
    int now = 1;

    while (1) {
        // 못 찾는 경우 1. 100은 단지 최대 크기로 정한 조건일뿐
        if (now > 100) return 0;
        // 못 찾는 경우 2.
        if (tree[now] == 0) return 0;

        if (tree[now] == v) return 1;

        // v가 현재 노드보드 크면 2n + 1
        if (tree[now] < v) {
            now = (now * 2) + 1;
        }
        // 작으면 2n
        else {
            now *= 2;
        }
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    insert(4);
    insert(2);
    insert(9);
    insert(7);
    insert(15);
    insert(99);

    cout << find(7) << endl;

    return 0;
}