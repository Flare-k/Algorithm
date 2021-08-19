#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 하나씩만 입을 때 = 총개수
// 조합해서 입을 때 = 종류 수의 곱

unordered_map<string, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    string a, b;

    while (t--) {
        m.clear();

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            m[b]++;
        }

        int sum = 1;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            sum *= (iter->second + 1);
        }

        cout << sum - 1 << '\n';

    }


    return 0;
}