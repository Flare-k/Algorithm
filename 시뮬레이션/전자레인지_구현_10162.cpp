#include <iostream>
#include <vector>
using namespace std;

int button[3] = {300, 60, 10};
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < 3; i++) {
        if (T >= button[i]) {
            ans.push_back(T / button[i]);
        }
        else {
            ans.push_back(0);
        }
        
        T %= button[i];
    }

    if (T == 0) {
        for (int num : ans) {
            cout << num << ' ';
        }
    }
    else {
        cout << -1 << '\n';
    }

    return 0;
}