#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

multiset<int> s;    // multiset: 내부적으로 오름차순 정렬

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int testCase;
    cin >> testCase;

    while (testCase--) {
        
        s.clear();

        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            char cmd;
            int num;
            cin >> cmd >> num;

            if (cmd == 'I') {
                s.insert(num);
            }
            else {
                if (!s.empty() && num == 1) {    // 최댓값 삭제
                    auto iter = s.end();
                    iter--;
                    s.erase(iter);
                }
                else if (!s.empty() && num == -1) {    // 최솟값 삭제
                    s.erase(s.begin());
                }
            }
        }

        if (s.empty()) cout << "EMPTY" << '\n';
        else {
            auto endElem = s.end();
            endElem--;
            cout << *endElem << ' ' << *s.begin() << '\n';
        }
        
    }

    return 0;
}