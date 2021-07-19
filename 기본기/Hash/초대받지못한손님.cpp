#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
using namespace std;

multimap<string, int> m;
unordered_map<string, int> cnt;

int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int age;
        cin >> name >> age;
        m.insert({name, age});
        cnt[name]++;
    }

    for (auto i = cnt.begin(); i != cnt.end(); ++i) {
        if (i->second > 1) {    // 이름이 두개이상인 경우 확인
            // 이름 출력
            cout << i->first << '\n';
            // 나이 출력
            auto mi = m.equal_range(i->first);
            for (auto j = mi.first; j != mi.second; ++j) {
                cout << j->second << ' ';
            }
        }
    }

    return 0;
}