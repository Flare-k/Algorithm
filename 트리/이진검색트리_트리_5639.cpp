#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX 10001
using namespace std;
/*
평범한 이진 탐색 트리의 치명적인 약점이 바로, 트리의 균형이 크게 나빠질 수 있다는 것
오름차순으로 값을 넣다보면 금방 터지는 순간이 오기마련
*/
int tree[MAX];

// 후위 순회
void postorder(int parent, int child) {
    if (parent == child) return;

    if (parent == child - 1) {
        cout << tree[parent] << '\n';
        return;
    }

    int idx = parent + 1;

    while (1) {
        if (!(idx < child && tree[idx] < tree[parent])) break;
        idx++;
    }

    postorder(parent + 1, idx);
    postorder(idx, child);

    cout << tree[parent] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num, idx = 0;
    
    while (cin >> num) {
        tree[idx++] = num;
    }

    postorder(0, idx);

    return 0;
}

/*
         50
        /   \
      30      98
     /  \    /
    24   45 52   
   /  \       \
  5    28      60       
*/