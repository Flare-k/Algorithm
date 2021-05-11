#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 덧셈기
// 1 2 3 4 5 -> 3 3 4 5 - > 4 5 6 -> 6 9 -> 15
priority_queue<int> pq;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pq.push(-1);
    pq.push(-2);
    pq.push(-3);
    pq.push(-4);
    pq.push(-5);

    while (1) {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();

        ans.push_back(a + b);
        
        if (pq.empty()) break;
        pq.push(-(a + b));
    }

    sort(ans.begin(), ans.end());

    for (auto n : ans) {
        cout << n << " ";
    }

    return 0;
}