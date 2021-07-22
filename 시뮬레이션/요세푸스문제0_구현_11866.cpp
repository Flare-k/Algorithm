#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque<int> dq;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    while (!dq.empty()) {
        int cnt = K;

        while (cnt != 0) {
            cnt--;
            int num = dq.front();
            dq.pop_front();
            if (cnt == 0) ans.push_back(num);
            else dq.push_back(num);
        }
    }

    cout << "<";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1) cout << ans[i];
        else cout << ans[i] << ", ";
    }
    cout << ">";

    return 0;
}