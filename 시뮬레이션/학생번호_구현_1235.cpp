#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

vector<string> students;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string number;
        cin >> number;
        reverse(number.begin(), number.end());
        students.push_back(number);
    }
    
    long long cnt = 1;

    while (1) {
        map<string, long long> m;

        long long check = 1;

        for (int i = 0; i < n; i++) {
            if (m.find(students[i].substr(0, cnt)) != m.end()) {
                check = 0;
                break;
            }
            m[students[i].substr(0, cnt)] = 1;
        }

        if (check) break;

        cnt++;
    }

    cout << cnt;

    return 0;
}