#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int num;
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        cin >> num;
        sum += num;
        m[num]++;
    }

    int maxcnt = -21e8;
    int maxx;

    for (auto i = m.begin(); i != m.end(); i++) {
        if (maxcnt < i->second) {
            maxcnt = i->second;
            maxx = i->first;
        }
    }

    cout << sum / 10 << '\n';
    cout << maxx << '\n';

    return 0;
}