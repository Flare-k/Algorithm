#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ans.push_back(a);
    }

    sort(ans.begin(), ans.end());

    if (ans.size() == 1) {
        cout << ans.front() * ans.front();
    }
    else {
        cout << ans.front() * ans.back();
    }
}