#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

// 절대값, 원본값
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, num;
    cin >> n;

    vector<int> ans;
    
    while (n--) {
        cin >> num;

        if (num != 0) {
            pq.push({abs(num), num});
        }
        else {
            if (!pq.empty()) {
                ans.push_back(pq.top().second);
                pq.pop();
            }
            else {
                ans.push_back(0);
            }
        }
    }

    for (int num : ans) {
        cout << num << '\n';
    }

    return 0;
}