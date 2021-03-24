#include <iostream>
#include <queue>
using namespace std;

// default: Min Heap
priority_queue<int> pq;

// Max Heap
priority_queue<int, vector<int>, greater<int>> q;

struct Node {
    int a;
    int b;
};

priority_queue<Node> nq;

bool operator<(Node v, Node tar) {
    // tar 우선순위 높으면 True
    // tar 우선순위 낮으면 False

    // 우선순위 조건
    // 1. a 오름차순
    // 2. b 내림차순

    if (tar.a < v.a) return true;
    if (tar.a > v.a) return false;

    return tar.b > v.b;
}

int main() {
    pq.push(3);
    pq.push(6);
    pq.push(1);
    pq.push(3);
    pq.push(8);

    q.push(3);
    q.push(6);
    q.push(1);
    q.push(3);
    q.push(8);

    nq.push({1, 2});
    nq.push({5, 6});
    nq.push({3, 4});
    nq.push({2, 5});
    nq.push({4, 7});

    // Heap Sort
    cout << "min Heap" << '\n';
    for (int i = 0; i < 5; i++) {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << "\n\nmax Heap" << '\n';
    for (int i = 0; i < 5; i++) {
        cout << q.top() << " ";
        q.pop();
    }


    int n = nq.size();
    cout << "\n\nNode Heap" << '\n';
    for (int i = 0; i < n; i++) {
        cout << nq.top().a << ", " << nq.top().b << '\n';
        nq.pop();
    }
}