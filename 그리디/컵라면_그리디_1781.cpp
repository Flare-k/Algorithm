#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int deadline, cup;
};

bool cmp(Node& a, Node& b) {
    if (a.deadline < b.deadline) return true;
    else if (a.deadline == b.deadline) return a.cup > b.cup;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<Node> arr;

    for (int i = 0; i < N; i++) {
        int d, c;
        cin >> d >> c;
        arr.push_back({d, c});
    }

    sort(arr.begin(), arr.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> pq;

    for (Node v : arr) {
        pq.push(v.cup);
        if (pq.size() > v.deadline) pq.pop();
    }

    long long answer = 0;

    while (!pq.empty()) {
        answer += pq.top();
        pq.pop();
    }

    cout << answer;

    return 0;
}