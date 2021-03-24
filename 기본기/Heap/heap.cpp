#include <iostream>
using namespace std;

int heap[100];
int hn;

void insert(int v) {
    heap[++hn] = v;

    int now = hn;
    int parent;

    while (1) {
        parent = now / 2;

        if (now == 1) break; // now가 root일 경우
        if (heap[now] >= heap[parent]) break; // parent가 작으면 정상
        swap(heap[now], heap[parent]);

        now = parent;
    }
}

int top() {
    return heap[1];
}

int pop() {
    heap[1] = heap[hn]; // 맨뒤에 있는걸 맨앞으로
    heap[hn--] = 0;

    int now = 1;
    int son;

    while (1) {
        son = now * 2;
        if (son + 1 <= hn && heap[son] > heap[son + 1]) son++;   // 만약 오른쪽이 더 작으면 오른쪽 선택
        if (son > hn || heap[now] <= heap[son]) break;  // 부모보다 크다면 정상

        swap(heap[now], heap[son]);
        now = son;
    }

    return 0;
}

int main() {
    insert(3);
    insert(6);
    insert(1);
    insert(3);
    insert(8);

    // HeapSort
    for (int i = 0; i < 5; i++) {
        cout << top() << " ";
        pop();
    }

    return 0;
}