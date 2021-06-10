#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;


int P, D;
long long maxAns;
map<pair<long long, int>, bool> check;
bool flag;

void run(int level, long long num) {
    if (check.count({num, level}) || D < to_string(num).length()) return;

    check[{num, level}] = true;

    if (level == P) {
        maxAns = max(maxAns, num);
        flag = true;
        return;
    }

    for (int i = 2; i <= 9; i++) {
        run(level + 1, num * i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> D >> P;
    run(0, 1);

    if (flag) cout << maxAns;
    else cout << -1;

    return 0;
}