#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;

struct Node {
    int value, idx;
};

deque<Node> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        if (!dq.empty() && dq.front().idx <= i - L) {
            dq.pop_front();
        }

        while (!dq.empty() && dq.back().value > arr[i]) {
            dq.pop_back();
        }

        dq.push_back({arr[i], i});  // 최솟값 후보들 저장
        cout << dq.front().value << ' ';
    }

    return 0;
}